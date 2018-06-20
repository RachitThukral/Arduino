int motor = 16; // initialise the pin number of motor
void setup() 
{ }

// the loop function runs over and over again forever
void loop() 
{
  analogWrite(motor, 255);        // Setting the voltage level
  delay(4000);                    // Delay of 4 seconds
  
  analogWrite(motor, 170);
  delay(4000);
  
 // analogWrite(motor, 85);
 // delay(4000);
}
