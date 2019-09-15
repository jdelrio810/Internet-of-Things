int sensorPin = A0;    
float sensorValue = 0;  
int led = 5; //pin D1 

void setup() {

  pinMode(sensorPin,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(115200);
 
}

void loop() {
  
  sensorValue = (3.3*analogRead(sensorPin))/1023;
  analogWrite(led,analogRead(sensorPin));
  Serial.println(sensorValue);
  delay(1000);
  
}
