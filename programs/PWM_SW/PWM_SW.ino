void setup() {
  // put your setup code here, to run once:
pinMode(D4, OUTPUT);
pinMode(D5, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(D5)){
    digitalWrite(D4, HIGH);
    delayMicroseconds(500);
    digitalWrite(D4, LOW);
    delayMicroseconds(1500);
  }
  else{
    digitalWrite(D4, HIGH);
    delayMicroseconds(1500);
    digitalWrite(D4, LOW);
    delayMicroseconds(500);
  }
}
