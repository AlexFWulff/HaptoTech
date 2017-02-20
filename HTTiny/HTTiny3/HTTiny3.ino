const int motorPin = 1;
const int IRPin = 1;//Remeber - this is not the actual pin just the first analog pin
const int enablePin = 3;
const int ledPin = 4;

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
  
  if (distance < 27 ) {
    digitalWrite(motorPin, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(distance*5);
    digitalWrite(motorPin, LOW);
    digitalWrite(ledPin, LOW);
    delay(distance*5);
  }
  
  else {
    digitalWrite(motorPin, LOW);
    digitalWrite(ledPin, LOW);
  }
}

int getDistance() {
  //Calibrated for 3.3 V
  int sensorValue = analogRead(IRPin);
  int distanceVal = 48.223 * pow(2.7182818284, (-0.004*sensorValue));
  return distanceVal;
}
