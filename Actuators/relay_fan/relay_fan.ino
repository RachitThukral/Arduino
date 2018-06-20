int fan = 12; // initialise the pin number
int button = 14;  // initialise the pin number of button
void setup() 
{
  pinMode(fan, OUTPUT); //setting the mode of pin (input/output)
  pinMode(button, INPUT); //setting the mode of button (input/output)
 }

// the loop function runs over and over again forever
void loop() 
{
  if(digitalRead(button))    // Checking if button is high
  {
        digitalWrite(fan, HIGH);   // turn the fan OFF 
  }
  else
  {
      digitalWrite(fan, LOW);     // turn the fan ON
  }
}
