int sensorPin = A0;    
float sensorValue = 0;  
float voltaje;

void setup() {

  pinMode(sensorPin,INPUT);
  Serial.begin(115200);
 
}

void loop() {
  
  sensorValue = analogRead(sensorPin);
  voltaje = ?
  Serial.println(sensorValue);
  delay(1000);
  
}
