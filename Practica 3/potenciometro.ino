int sensorPin = A0;    
float sensorValue = 0;  
int led = 5; //pin D1 
float voltaje;

void setup() {

  pinMode(sensorPin,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(115200);
 
}

void loop() {
  
  sensorValue = analogRead(sensorPin);
  voltaje = ?
  analogWrite(led,analogRead(sensorPin));
  Serial.println(voltaje);
  delay(1000);
  
}
