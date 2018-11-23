int LED = D4; // pin number for LED
int button = D5;  // pin number of button

void setup() {
  pinMode(LED, OUTPUT); //set LED as OUTPUT
  pinMode(button, INPUT); //set LED as INPUT
}

void loop() {
  if(digitalRead(button)==0){    // Checking if button is high
    digitalWrite(LED, LOW);   // turn the LED 1 ON
  }
  else{
    digitalWrite(LED, HIGH);     // turn the LED 1 OFF
  }
}
