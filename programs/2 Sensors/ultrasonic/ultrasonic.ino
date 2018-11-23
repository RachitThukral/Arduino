int trigPin = D4;
int echoPin = D3;
long duration;
int distance;
void setup(){
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  digitalWrite(trigPin, LOW);
  Serial.print("start");
}
void loop(){
  digitalWrite(trigPin, HIGH);    //initial pulse
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);    //reads the echoPin, travel time in microseconds
  distance= duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(1000);
}
