// defines pins numbers
const int trigPin = 3;
const int echoPin = 5;
const int LED1=2;
const int LED2=0;
// defines variables
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
// Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  
  if(distance<=5)
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
  }
  
  else if(distance >5 && distance <= 10)
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
  }

  else if(distance >10 && distance <= 15)
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
  }

  else if(distance>15 && distance <= 20)
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
  }

  delay(500);
}
