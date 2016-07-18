#include <Arduino.h>

int motorPin = 1;
int IRPin = 1;//Remeber - this is not the actual pin just the first analog pin
int distance = 0;

void setup() {
  pinMode(IRPin, INPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
 distance = getDistance();
  
  if (distance < 10) {
    digitalWrite(motorPin, HIGH);
    delay(100);
    digitalWrite(motorPin, LOW);
    delay(50);
  }
  
  else if (distance < 20) {
    digitalWrite(motorPin, HIGH);
    delay(300);
    digitalWrite(motorPin, LOW);
    delay(100);
  }
  
  else if (distance < 27 ) {
    digitalWrite(motorPin, HIGH);
  }
  
  else {
    digitalWrite(motorPin, LOW);
  }
}

int getDistance() {
  //Calibrated for 3.3 V
  int sensorValue = analogRead(1);
  int distance = 48.223 * pow(2.7182818284, (-0.004*sensorValue));
  return distance;
}
