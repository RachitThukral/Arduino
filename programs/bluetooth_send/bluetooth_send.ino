void setup()
{
    Serial.begin(38400);   //Sets the baud for serial data transmission  
    Serial.swap();                             
}   
void loop()
{
   Serial.println("N"); //data to be sent
   delay(2000); //Delay of 2 seconds  
}

