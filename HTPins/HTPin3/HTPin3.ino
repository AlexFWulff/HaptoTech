//Globals
int distance = 0;

//Pins
int motorPin = 0;
int IRPin = 2;

void setup() {
  pinMode(IRPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
 distance = getDistance();
  
  if (distance < 100) {
    analogWrite(motorPin, 255);
    delay(500);
    analogWrite(motorPin, 0);
    delay(500);
  }
  
  else if (distance < 300) {
    analogWrite(motorPin, 150);
  }
  
  else if (distance < 750 ) {
    analogWrite(motorPin, 100);
  }
  
  else {
    analogWrite(motorPin, 0);
  }
}

int getDistance() {
 int value = analogRead(1);
  int inter = map(value, 127, 860, 860, 127);
  return inter;
}
