#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Uncomment one of the lines bellow for whatever DHT sensor type you're using!

const char* ssid = "FAMILIA CADENA";
const char* password = "Mei481SA";

int TRIG = 5;      // trigger en pin D1 
int ECO = 4;      // echo en pin D2
int lamp = 2;      // LED en pin D4
int DURACION;
int DISTANCIA;

// Change the variable to your Raspberry Pi IP address, so it connects to your MQTT broker
const char* mqtt_server = "192.168.0.6";

// Initializes the espClient. You should change the espClient name if you have multiple ESPs running in your home automation system
WiFiClient espClient;
PubSubClient client(espClient);


// Timers auxiliar variables
long now = millis();
long lastMeasure = 0;

// Don't change the function below. This functions connects your ESP8266 to your router
void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("WiFi connected - ESP IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(String topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  // If a message is received on the topic room/lamp, you check if the message is either on or off. Turns the lamp GPIO according to the message
  if(topic=="nivel_agua/lampara"){
      Serial.print("Changing Room lamp to ");
      if(messageTemp == "on"){
        digitalWrite(lamp, HIGH);
        Serial.print("On");
      }
      else if(messageTemp == "off"){
        digitalWrite(lamp, LOW);
        Serial.print("Off");
      }
  }
  Serial.println();
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
  
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");  
      // Subscribe or resubscribe to a topic
      // You can subscribe to more topics (to control more LEDs in this example)
      client.subscribe("nivel_agua/lampara");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {

  pinMode(TRIG, OUTPUT);  // trigger como salida
  pinMode(ECO, INPUT);    // echo como entrada
  pinMode(lamp, OUTPUT);   // LED como salida
  Serial.begin(115200);     // inicializacion de comunicacion serial a 9600 bps

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

}

// For this project, you don't need to change anything in the loop function. Basically it ensures that you ESP is connected to your broker
void loop() {

  if (!client.connected()) {
    reconnect();
  }
  if(!client.loop())
    client.connect("ESP8266Client");

  digitalWrite(TRIG, HIGH);     // generacion del pulso a enviar
  delay(1);       // al pin conectado al trigger
  digitalWrite(TRIG, LOW);    // del sensor
  
  DURACION = pulseIn(ECO, HIGH);  // con funcion pulseIn se espera un pulso
            // alto en Echo
        
  DISTANCIA = DURACION / 58.2;    // distancia medida en centimetros
  Serial.println(DISTANCIA);    // envio de valor de distancia por monitor serial
  if(DISTANCIA > 30){
    digitalWrite(lamp,HIGH);
  }
  else{
    digitalWrite(lamp,LOW);
  }
  delay(200);       // demora entre datos
    
    // Check if any reads failed and exit early (to try again).
    if (isnan(DISTANCIA)) {
      Serial.println("Fallo lectura del sensor!");
      return;
    }
    
    static char distancia[7];
    dtostrf(DISTANCIA, 6, 2, distancia);
    
    // Publishes valor del sensor
    client.publish("nivel_agua/distancia",distancia );
    Serial.print("luz: ");
    Serial.println(distancia);
    delay(500);
    
  }
