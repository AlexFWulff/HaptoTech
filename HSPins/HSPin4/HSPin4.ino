//Alrighty - this is the one! We're using a good function rather than map to convert distances
//we're using the correct ANALOG pin to read, and we're using a transitor for
//the motor. This should work great. Pin 2 is ir, with the VIN connected to the
//3.3v on the trinket. Pin 0 is connected to the middle of the transistor.
//I have a picture saved on my phone somewhere....

//Globals
int distance = 0;

//Pins
int motorPin = 0;
int IRPin = 2;

void setup() {
  pinMode(IRPin, INPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(1, OUTPUT);
}

void loop() {
 distance = getDistance();
  
  if (distance < 6) {
    digitalWrite(motorPin, HIGH);
    digitalWrite(1, HIGH);
    delay(100);
    digitalWrite(motorPin, LOW);
    digitalWrite(1, LOW);
    delay(50);
  }
  
  else if (distance < 12) {
    digitalWrite(motorPin, HIGH);
    digitalWrite(1, HIGH);
    delay(300);
    digitalWrite(motorPin, LOW);
    digitalWrite(1, LOW);
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
