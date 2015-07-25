#include <Arduino.h>
#include <WProgram.h>

int motorPin = 4;
int IRPin = 1;//Remeber - this is not the actual pin just the first analog pin
int distance = 0;

void setup() {
  pinMode(IRPin, INPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
 distance = getDistance();
  
  if (distance < 6) {
    digitalWrite(motorPin, HIGH);
    digitalWrite(3, HIGH);
    delay(100);
    digitalWrite(motorPin, LOW);
    digitalWrite(3, LOW);
    delay(50);
  }
  
  else if (distance < 12) {
    digitalWrite(motorPin, HIGH);
    digitalWrite(3, HIGH);
    delay(300);
    digitalWrite(motorPin, LOW);
    digitalWrite(3, LOW);
    delay(100);
  }
  
  else if (distance < 16 ) {
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
