
#include <SharpIR.h>

SharpIR sharp(1, 25, 93, 20150);

//Globals
int distance = 0;

//Pins
int motorPin = 0;
int IRPin = 1;

void setup() {
  pinMode(IRPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
 distance = sharp.distance();
  
  if (distance < 30) {
    analogWrite(motorPin, 255);
    delay(500);
    analogWrite(motorPin, 0);
    delay(500);
  }
  
  else if (distance < 50) {
    analogWrite(motorPin, 150);
  }
  
  else if (distance < 80) {
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

double getDistance()
{
  double sensorValue       =   0.0 ;
  int distanceFromIR    =   0.0 ;
  sensorValue = analogRead( IRPin ); 
  sensorValue *= .0049;
  distanceFromIR = 3*pow ( ( sensorValue - 3 ) , 4 ) + 15;
  return distanceFromIR;
}
