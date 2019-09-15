int sensorPin = A0;    
float sensorValue = 0;  

void setup() {

  pinMode(sensorPin,INPUT);
  Serial.begin(115200);
 
}

void loop() {
  
  sensorValue = (3.3*analogRead(sensorPin))/1023;
  Serial.println(sensorValue);
  delay(1000);
  
}
