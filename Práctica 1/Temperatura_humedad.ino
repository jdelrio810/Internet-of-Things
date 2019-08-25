#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
#include "DHT.h" 
#define DHTPIN PIN_GPIO 
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE); 

char ssid[] = "Nombre de la red";
char pass[] = "Contraseña";
int status = WL_IDLE_STATUS;
WiFiClient  client;

unsigned long myChannelNumber = numero del canal;
const char * myWriteAPIKey = "Apikey";
void setup() {
WiFi.begin(ssid, pass); 
ThingSpeak.begin(client);
dht.begin();

Serial.begin(115200);
Serial.println();
Serial.print("Conectando a ");
Serial.print(ssid);

while (WiFi.status() != WL_CONNECTED)
{
delay(500);
Serial.print(".");
}

Serial.println();
Serial.println("Conectado a WiFi");
Serial.print("Dirección IP: ");
Serial.println(WiFi.localIP());

}

void loop() {
delay(2000);

float h = dht.readHumidity();
float t = dht.readTemperature();

Serial.print("Humedad: ");
Serial.print(h);
Serial.print(" %\t");
Serial.print("Temperatura: ");
Serial.print(t);
Serial.println(" *C\t ");

// Carga los valores a enviar
ThingSpeak.setField(1,t);
ThingSpeak.setField(2,h);

// Escribe todos los campos a la vez.
ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

Serial.println("¡Datos enviados a ThingSpeak!");

// Añadimos un retraso para limtitar el número de escrituras en Thinhspeak

delay (1000);
}
