int LED1 = 2; // initialise the pin number
int LDRsensor = 13;  // initialise the pin number 
void setup() {
  pinMode(LED1, OUTPUT); //setting the mode of pin (input/output)
  pinMode(LDRsensor, INPUT); //setting the mode of pin (input/output)
 }

// the loop function runs over and over again forever
void loop() {
  if(digitalRead(LDRsensor))    // Checking if there is no enough light
  {
        digitalWrite(LED1, LOW);   // turn the LED ON 
  }
  else
  {
      digitalWrite(LED1, HIGH);     // turn the LED OFF
  }
}
