void setup()
{
    Serial.begin(9600);   //Sets the baud for serial data transmission                               
}   
void loop()
{
   Serial.print("N"); //data to be sent
   delay(2000); //Delay of 2 seconds  
}

