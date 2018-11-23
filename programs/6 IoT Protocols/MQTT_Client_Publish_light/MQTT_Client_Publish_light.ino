#include <ESP8266WiFi.h>
#include <MQTTClient.h>
#include <Wire.h>
#include "TSL2561.h"

TSL2561 tsl(TSL2561_ADDR_FLOAT); 

const char* ssid = "rachit";
const char* password = "aaaa1111";

WiFiClient WiFiclient;
MQTTClient client;
int val=0;

void setup() {
  tsl.setGain(TSL2561_GAIN_16X);
  tsl.setTiming(TSL2561_INTEGRATIONTIME_13MS);
  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  delay(2000);

  Serial.print("connecting to MQTT broker...");
  client.begin("broker.shiftr.io", WiFiclient);
  connect();
}

void connect() {
  while (!client.connect("ETIL_pub", "try", "try")) {
    Serial.print(".");
  }
  Serial.println("\nconnected!");
//  client.subscribe("test_topic");
}

void loop() {
  client.loop();
  if(!client.connected()) {
    connect();
  }
  uint16_t x = tsl.getLuminosity(TSL2561_VISIBLE);
  client.publish("ETIL_light", (String)x);
  delay(2000);
}
