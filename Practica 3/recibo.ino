int led = 5;//pin D1

void setup () {
      Serial.begin(115200); //Inicializo el puerto serial a 115200 baudios
      pinMode( led , OUTPUT);
}
void loop () {
      if (Serial.available()) { //Si está disponible
            char c = Serial.read(); //Guardamos la lectura en una variable char
            if (c == 'n') { //Si es una 'n', enciendo el LED
                  digitalWrite(led,HIGH);
                  
            } else if (c == 'd') { //Si es una 'd', apago el LED
                  digitalWrite(led,LOW);
            } 
      }
}
