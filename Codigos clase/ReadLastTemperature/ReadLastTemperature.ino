
#include "ThingSpeak.h"

#include <ESP8266WiFi.h>

char ssid[] = "nombr";    //  your network SSID (name)
char pass[] = "password";   // your network password

int status = WL_IDLE_STATUS;
WiFiClient  client;


unsigned long weatherStationChannelNumber = 12397;
unsigned int temperatureFieldNumber = 4;

void setup() {

  WiFi.begin(ssid, pass);

  ThingSpeak.begin(client);
  Serial.begin(9600);

}

void loop() {
  // Read the latest value from field 4 of channel 12397
  float temperatureInF = ThingSpeak.readFloatField(weatherStationChannelNumber, temperatureFieldNumber);

  Serial.print("Temperatura actual: ");
  Serial.print(temperatureInF);
  Serial.print(" F     ");
    Serial.print((temperatureInF-32)/1.8);
  Serial.println("  C");

  delay(30000); // Note that the weather station only updates once a minute
}





