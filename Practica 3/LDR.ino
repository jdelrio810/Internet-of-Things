int sensorPin = A0; //pin A0 del NodeMCU   
float sensorValue = 0;  
float voltaje;
int led = 5 //pin D1;

void setup() {

  pinMode(sensorPin,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(115200);
 
}

void loop() {
  
  sensorValue = analogRead(sensorPin);
  voltaje = (3.3*(sensorValue)/1023);
  Serial.println(voltaje);
  delay(100);
  
}
  
