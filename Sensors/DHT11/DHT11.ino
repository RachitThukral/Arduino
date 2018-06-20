#include <esp8266.h> 
#include <dht.h>                                      //including DHT11 library
dht DHT;                                                
void setup() 
{
 Serial.begin(9600);                                // setting the baud rate
 delay(1000);
 }
 
 
void loop() 
{
 DHT.read11(D0);                                 // Read the sensor data
 
 String temp = (String)DHT.temperature;                   //Extract the temperature
 Serial.println("Temperature is: "+temp+"*C");       // Printing on serial monitor
 delay(1000);                                      //Delay of 1 second
 
 String humidity = (String)DHT.humidity;                // Extract the humidity
 Serial.println("Humidity is: "+humidity+"%");           // Printing on serial monitor
 delay(3000);                                       //Delay of 3 seconds
 }

