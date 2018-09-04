#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
int i,j;
#define OLED_ADDR   0x3C    // OLED display TWI address

Adafruit_SSD1306 display(-1);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);        // initialize and clear display
  display.clearDisplay();
  display.display();
  
  for(i=0;i<64;i++){      //make rectangle with single pixels
    display.drawPixel(0, i, WHITE);
    display.drawPixel(127, i, WHITE);
  }
  for(j=0;j<128;j++){
    display.drawPixel(j, 0, WHITE);
    display.drawPixel(j, 63, WHITE);
  }
  display.display();
}

void loop() {

}

