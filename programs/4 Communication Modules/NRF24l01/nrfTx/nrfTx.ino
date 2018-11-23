#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00002";
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_1MBPS);
//  radio.stopListening();`
}
void loop() {
  const char text[] = "Hello World";
  Serial.println(radio.write(&text, sizeof(text)));
  Serial.println(text);
  delay(1000);
}
