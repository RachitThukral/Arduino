#include <ESP8266WiFi.h>
#include <MQTTClient.h>

const char* ssid = "rachit";
const char* password = "aaaa1111";

WiFiClient WiFiclient;
MQTTClient client;
int val=0;

void setup() {
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
  val++;
  client.publish("ETIL_light", (String)val);
  if(val==10)
    val=0;

  delay(1000);  
}
