#include <Arduino.h>

const int motorPin = 1;
const int IRPin = 1;//Remeber - this is not the actual pin just the first analog pin
const int enablePin = 3;
const int ledPin = 4;

int lastDistance = 1000;
int distance = 0;

void setup() {
  pinMode(IRPin, INPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(enablePin, HIGH);
}

void loop() {
 distance = getDistance();
 
 //For power saving
// while(distance == lastDistance) {
//   digitalWrite(enablePin, LOW);
//   delay(250);
//   digitalWrite(enablePin, HIGH);
//   delay(10);
//   distance = getDistance();
// }
  
  if (distance < 10) {
    digitalWrite(motorPin, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(motorPin, LOW);
    digitalWrite(ledPin, LOW);
    delay(50);
  }
  
  else if (distance < 20) {
    digitalWrite(motorPin, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(300);
    digitalWrite(motorPin, LOW);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
  
  else if (distance < 27 ) {
    digitalWrite(motorPin, HIGH);
    digitalWrite(ledPin, HIGH);
  }
  
  else {
    digitalWrite(motorPin, LOW);
    digitalWrite(ledPin, LOW);
  }
  
  lastDistance = distance;
}

int getDistance() {
  //Calibrated for 3.3 V
  int sensorValue = analogRead(IRPin);
  int distanceVal = 48.223 * pow(2.7182818284, (-0.004*sensorValue));
  return distanceVal;
}
