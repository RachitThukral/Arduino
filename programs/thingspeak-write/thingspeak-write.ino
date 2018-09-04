#include <ESP8266WiFi.h>
#include "ThingSpeak.h"
#include <Wire.h>
#include "TSL2561.h"
 
const char* ssid     = "rachit";
const char* password = "aaaa1111";
unsigned long myChannelNumber = 456392;
const char * myWriteAPIKey = "ZXD3AGAF7HECKCVL";
 
WiFiClient WiFiclient;
TSL2561 tsl(TSL2561_ADDR_FLOAT);

void setup() {
  Serial.begin(115200);
  tsl.setGain(TSL2561_GAIN_16X);
  tsl.setTiming(TSL2561_INTEGRATIONTIME_13MS);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
   delay(500);
   Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(WiFiclient);
}
 
void loop() {
  uint16_t x = tsl.getLuminosity(TSL2561_VISIBLE); 
  Serial.println(x);
  ThingSpeak.setField(1, (String)x);
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  delay(17000);
}

