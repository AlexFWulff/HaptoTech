
#include <SharpIR.h>

SharpIR sharp(2, 25, 93, 20150);

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
 distance = sharp.distance();
  
  if (distance < 15) {
    analogWrite(motorPin, 255);
    delay(500);
    analogWrite(motorPin, 0);
    delay(500);
  }
  
  else if (distance < 25) {
    analogWrite(motorPin, 150);
  }
  
  else if (distance < 35) {
    analogWrite(motorPin, 100);
  }
  
  else {
    analogWrite(motorPin, 0);
  }
  /*
  
  else if (distance < 90) {
    analogWrite(motorPin, 125);
    delay(500);
    analogWrite(motorPin, 0);
    delay(500);
    Serial.println(distance);
  }
  */
  
}
