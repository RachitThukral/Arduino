#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
int i,j;
// OLED display TWI address
#define OLED_ADDR   0x3C

Adafruit_SSD1306 display(-1);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup() {
  // initialize and clear display
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.display();

for(i=0;i<64;i++)
{
  display.drawPixel(0, i, WHITE);
  display.drawPixel(127, i, WHITE);
  }

  for(j=0;j<128;j++)
{
  display.drawPixel(j, 0, WHITE);
  display.drawPixel(j, 63, WHITE);
  }
  
// update display with all of the above graphics
  display.display();
}

void loop() {
  // put your main code here, to run repeatedly:

}

