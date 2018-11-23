int buzzer = D8; // pin number of buzzer
int sensor = D7;  // pin number of sensor

void setup() {
  pinMode(buzzer, OUTPUT); //set buzzer as OUTPUT
  pinMode(sensor, INPUT); //set sesnor as INPUT
 }

void loop() {
  if(digitalRead(sensor)){    // Checking the sensor
    digitalWrite(buzzer, HIGH);   // turn the buzzer ON 
  }
  else{
      digitalWrite(buzzer, LOW);     // turn the buzzer OFF
  }
}
