char data = 0;            //Variable for storing received data
int LED = D4;
void setup()
{
    Serial.begin(38400);   //Sets the baud for serial data transmission           
    pinMode(LED, OUTPUT);   
    digitalWrite(LED, HIGH);                 
}   
void loop()
{
   if(Serial.available() > 0)      // Send data only when you receive data:
   {
      data = Serial.read();        //Read the incoming data & store into data
      Serial.print(data);          //Print Value inside data in Serial monitor       
      if(data == '1')
      {
        digitalWrite(LED, LOW);
      }
      else if(data == '0')
      {
        digitalWrite(LED, HIGH);
      }
   }
}
