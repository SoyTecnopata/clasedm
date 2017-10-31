
#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

char ssid[] = "AXTEL XTREMO-4403";    //  your network SSID (name)
char pass[] = "03674403";   // your network password
int status = WL_IDLE_STATUS;
WiFiClient  client;

/*Se accede a estos datos en ThingSpeak > Channels > My Channels > "Nombre del Canal" > Data Import / Export*/
unsigned long myChannelNumber = 355076; //Channel ID [Sacado de ThingSpeak]
const char * myWriteAPIKey = "2H8XKBDLW518EURC"; //En API Request [Sacado de ThingSpeak]

float tempC = 0;
float tempF = 0;
float humidity = 0;

void setup() {

  randomSeed(42); //Para prueba en el canal, semilla donde empieza el Random

  Serial.begin(9600); //Inicio de monitor Serial, !!!!Herramientas>Debug Port>"Serial"
  delay(1000); //Espera

  /*Conexion a Red Wifi*/

  Serial.println();
  Serial.println();
  Serial.print("Connecting to "); //Desplegado en el monitor Serial
  Serial.println(ssid);  //Nombre de la red en la cual se va a conectar

  WiFi.begin(ssid, pass);
  ThingSpeak.begin(client);
  Serial.begin(9600);


  /*Si la conexión fue exitosa*/
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); //Muestra la dirección IP de la red WiFi a la que está conectado
  ThingSpeak.begin(client);
}


void loop() {

  /*Si la conexión fue exitosa*/

  int prub = random(17, 41); //Valor Random generado entre 17 y 41

  Serial.print("Valor de prueba: ");
  Serial.println(prub);

  //int sensado =

  readSensor();
  printOut();
  delay(20000);


  /*Mandar información a ThingSpeak=TS*/
  // En cada canal de TS se pueden llenar hasta 8 campos diferentes
  ThingSpeak.setField(1, tempC);
  ThingSpeak.setField(2, humidity);
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

  //ThingSpeak.writeField(myChannelNumber,   1 ,    tempC  ,   myWriteAPIKey);
  //ThingSpeak.writeField(myChannelNumber,   2 ,    humidity  ,   myWriteAPIKey);
  //   ^     |     ^   |       ^       |   ^  |       ^      |    ^
  //Libreria | escribir| numero canal  |campo |valor a enviar| API KEY
  //delay(20000); // La suscripción de ThingSpeak actual, acepta datos cada 15 segundo



}

void readSensor()
{
  // Read values from the sensor
  //Serial.print("Sensando");
  tempC = random(17, 41);
  tempF = random(17, 41);
  humidity = random(17, 41);
  //Serial.print("Sensado listo");
}
//-------------------------------------------------------------------------------------------
void printOut()
{
  Serial.print("Temp = ");
  //Serial.print(tempF);
  //Serial.print("F, ");
  Serial.print(tempC);
  Serial.println("C");
  Serial.print("Humidity = ");
  Serial.print(humidity);
  Serial.println("%");
}
