int LED1 = 2; // initialise the pin number
int button = 14;  // initialise the pin number of button
void setup() {
  pinMode(LED1, OUTPUT); //setting the mode of pin (input/output)
  pinMode(button, INPUT); //setting the mode of button (input/output)
 }

// the loop function runs over and over again forever
void loop() {
  if(digitalRead(button))    // Checking if button is high
  {
        digitalWrite(LED1, HIGH);   // turn the LED 1 OFF 
  }
  else
  {
      digitalWrite(LED1, LOW);     // turn the LED 1 ON
    }
}
