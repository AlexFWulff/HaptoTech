//Pins
int motorPin = 3;
int trigPin = 11;
int echoPin = 10;
int trigPin2 = 13;
int echoPin2 = 12;
int motorPin2 = 9;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(motorPin2, OUTPUT);
  
}

void loop() {
  int distance = checkDistance();
  int distance2 = checkDistance();
  
  if (distance < 15) {
    analogWrite(motorPin, 200);
    delay(500);
    analogWrite(motorPin, 0);
    delay(200);
  }
  
  else if (distance < 40) {
    analogWrite(motorPin, 150);
    delay(400);
    analogWrite(motorPin, 0);
    delay(400);
  }
  
  else if (distance < 60) {
    analogWrite(motorPin, 150);
    delay(300);
    analogWrite(motorPin, 0);
    delay(500);
  }
  
  else {
    analogWrite(motorPin, 0);
  }
  
  //Ultra 2
  
  if (distance2 < 15) {
    analogWrite(motorPin2, 200);
    delay(500);
    analogWrite(motorPin2, 0);
    delay(200);
  }
  
  else if (distance2 < 40) {
    analogWrite(motorPin2, 150);
    delay(400);
    analogWrite(motorPin2, 0);
    delay(400);
  }
  
  else if (distance2 < 60) {
    analogWrite(motorPin2, 150);
    delay(300);
    analogWrite(motorPin2, 0);
    delay(500);
  }
  
  else {
    analogWrite(motorPin2, 0);
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

int checkDistance2() {
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
