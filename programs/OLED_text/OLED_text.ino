#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#define OLED_ADDR   0x3C  // OLED display TWI address
Adafruit_SSD1306 display(-1);
void setup() {
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);   // initialize and clear display
  display.clearDisplay();
  display.display();
  
  display.setTextSize(2);     //set text size
  display.setTextColor(WHITE);    //set text color
  display.setCursor(0,0);     //set start coordinates for printing
  display.print("ETI Labs");      //dispaly text
  display.display();
  Serial.println("ok");
}

void loop() {

}

