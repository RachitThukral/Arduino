#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

// OLED display TWI address
#define OLED_ADDR   0x3C

Adafruit_SSD1306 display(-1);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

// WiFi Parameters
const char* ssid = "Priyam";
const char* password = "priyam123456";

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.display();
  Serial.begin(115200);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
}

void loop() {
  // Check WiFi Status
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;  //Object of class HTTPClient
    http.begin("http://api.worldweatheronline.com/premium/v1/tz.ashx?q=28.6671878,77.2079042&format=json&key=40baf3d326f942ffb7b91155180506");
    int httpCode = http.GET();
    //Check the returning code                                                                  
    if (httpCode > 0) {
      // Get the request response payload
      String payload = http.getString();
      // TODO: Parsing
const size_t bufferSize = 2*JSON_ARRAY_SIZE(1) + JSON_OBJECT_SIZE(1) + 2*JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(3) + 140;
DynamicJsonBuffer jsonBuffer(bufferSize);
JsonObject& root = jsonBuffer.parseObject(payload);

const char* data_request0_type = root["data"]["request"][0]["type"]; // "LatLon"
const char* data_request0_query = root["data"]["request"][0]["query"]; // "Lat 28.67 and Lon 77.21"

JsonObject& data_time_zone0 = root["data"]["time_zone"][0];
const char* data_time_zone0_localtime = data_time_zone0["localtime"]; // "2018-06-05 14:47"
const char* data_time_zone0_utcOffset = data_time_zone0["utcOffset"]; // "5.50"
const char* data_time_zone0_zone = data_time_zone0["zone"]; // "Asia/Kolkata"
Serial.println(data_time_zone0_localtime);
// display a line of text
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.clearDisplay();
  display.setCursor(15,5);
  display.print("ETI LABS\n");
  display.setCursor(1,32);
  display.print(data_time_zone0_localtime);
// update display with all of the above graphics
  display.display();
    }
    http.end();   //Close connection
  }
  // Delay
  delay(20000);
}
