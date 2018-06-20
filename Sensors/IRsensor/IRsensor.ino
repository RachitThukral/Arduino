int buzzer = 15; // initialise the pin number
int irsensor = 13;  // initialise the pin number of button
void setup() {
  pinMode(buzzer, OUTPUT); //setting the mode of pin (input/output)
  pinMode(irsensor, INPUT); //setting the mode of pin (input/output)
 }

// the loop function runs over and over again forever
void loop() {
  if(digitalRead(irsensor))    // Checking if IR sensor detected the obstacle
  {
        digitalWrite(buzzer, LOW);   // turn the buzzer ON 
  }
  else
  {
      digitalWrite(buzzer, HIGH);     // turn the buzzer OFF
    }
}
