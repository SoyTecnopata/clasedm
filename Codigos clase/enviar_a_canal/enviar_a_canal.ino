
#include "ThingSpeak.h"

#include <ESP8266WiFi.h>
//char ssid[] = "AXTEL XTREMO-4403";    //  your network SSID (name)
//char pass[] = "03674403";   // your network password

char ssid[] = "ESTUDIANTES_CIA";    //  your network SSID (name)
char pass[] = "*k%A2S!+";   // your network password

int status = WL_IDLE_STATUS;
WiFiClient  client;

unsigned long myChannelNumber = 355076;
const char* myWriteAPIKey = "2H8XKBDLW518EURC";

void setup() {
  
  WiFi.begin(ssid, pass);
  ThingSpeak.begin(client);
  randomSeed(analogRead(0));
  Serial.begin(9600);

}

void loop() {
  // read the input on analog pin 0:
  int Value = random(100);
   ThingSpeak.writeField(myChannelNumber, 1, Value, myWriteAPIKey);
   Serial.println(Value);
  delay(20000); // ThingSpeak will only accept updates every 15 seconds.
}
