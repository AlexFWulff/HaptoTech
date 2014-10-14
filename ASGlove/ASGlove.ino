

//Pins
int motorPin = 3;
int trigPin = 5;
int echoPin = 4;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int distance = checkDistance();
  
  if (distance < 30) {
    analogWrite(motorPin, 200);
    delay(50);
    analogWrite(motorPin, 0);
    delay(50);
    Serial.println(distance);
  }
  
  else if (distance < 50) {
    analogWrite(motorPin, 175);
    delay(100);
    analogWrite(motorPin, 0);
    delay(100);
    Serial.println(distance);
  }
  
  else if (distance < 70) {
    analogWrite(motorPin, 150);
    delay(250);
    analogWrite(motorPin, 0);
    delay(250);
    Serial.println(distance);
  }
  
  else if (distance < 90) {
    analogWrite(motorPin, 125);
    delay(500);
    analogWrite(motorPin, 0);
    delay(500);
    Serial.println(distance);
  }
  
  else if (distance < 110) {
    analogWrite(motorPin, 100);
    delay(750);
    analogWrite(motorPin, 0);
    delay(750);
    Serial.println(distance);
  }
  
  else if (distance < 130) {
    analogWrite(motorPin, 75);
    delay(1000);
    analogWrite(motorPin, 0);
    delay(1000);
    Serial.println(distance);
  }
  
  else {
    analogWrite(motorPin, 0);
  }
}

int checkDistance() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  return distance;
  //Distance is in cm
}
