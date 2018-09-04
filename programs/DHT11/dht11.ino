#include "dht.h"
#define DHT11_PIN D7
dht DHT11;
void setup(){
  Serial.begin(9600);
  Serial.println("start");
  delay(1000);
}
void loop(){
  int chk = DHT11.read11(DHT11_PIN);
  Serial.println(chk);
  if(chk==0){
    Serial.print("Temp: ");
    Serial.print(DHT11.temperature);         // Printing the temperature on display.
    Serial.println("*C");     // Printing “ *C ”  on display.
    Serial.print("Relative Humidity: ");
    Serial.print(DHT11.humidity);     // Printing the humidity on display
    Serial.println("%");     // Printing “%” on display
  }
  else{
    Serial.println("Error");
  }
  delay(2000);
}

