
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
 
// Definimos parámetros
#define WIFISID "*************"
#define WIFIPASS "************"
 
// Definimos los parámetros para el IFTTT
#define HOSTIFTTT "maker.ifttt.com"
#define EVENTO "********"
#define IFTTTKEY "*************"

int sensorPin = A0;    
float sensorValue = 0;  
float voltaje;

ESP8266WiFiMulti WiFiMulti;
 
// Utilizamos la conexión SSL del ESP8266
WiFiClientSecure client;
 
// Variable que permite ejecutar una sola vez la función
bool ejecutado = false;
 
void setup() {
 Serial.begin(115200);
 delay(10);
 
 // Conectamos a la red WiFi
 WiFiMulti.addAP(WIFISID, WIFIPASS);
 
 Serial.println();
 Serial.println();
 Serial.print("Eperando a conectar a la WiFi... ");
 
 while (WiFiMulti.run() != WL_CONNECTED) {
 Serial.print(".");
 delay(500);
 }
 
 Serial.println("");
 Serial.println("WiFi conectada");
 Serial.println("Direccion IP: ");
 Serial.println(WiFi.localIP());
 
 delay(500);
 
 //Establecemos la semilla en un pin analogico
 randomSeed(analogRead(A0));
}
 
void loop() {
  
  
 // Hacemos la petición mediante SSL
  if (client.connect(HOSTIFTTT, 443)) {
    // Construimos la petición HTTP
    String toSend = "GET /trigger/";
    toSend += EVENTO;
    toSend += "/with/key/";
    toSend += IFTTTKEY;
    //toSend += "?value1=";
    //toSend += valor1;
    toSend += " HTTP/1.1\r\n";
    toSend += "Host: ";
    toSend += HOSTIFTTT;
    toSend += "\r\n";
    toSend += "Connection: close\r\n\r\n";
 
    client.print(toSend);
    delay(10000);
  }
 
  // Esperamos hasta que se hayan enviado todos los datos
  client.flush();
  // Desconectamos del cliente
  client.stop();
 }
