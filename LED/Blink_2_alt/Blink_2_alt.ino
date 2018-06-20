int LED1 = 2; // initialise the pin number
int LED2 = 0;
void setup() {
  pinMode(LED1, OUTPUT); //setting the mode of pin (input/output)
  pinMode(LED2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED1, HIGH);   // turn the LED 1 off (HIGH is the voltage level)
  digitalWrite(LED2, LOW);     // turn the LED 2 on (LOW is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED1, LOW);    // turn the LED on by making the voltage LOW
  digitalWrite(LED2, HIGH);   // turn the LED off by making the voltage HIGH
  delay(2000);                       // wait for 2 seconds
}
