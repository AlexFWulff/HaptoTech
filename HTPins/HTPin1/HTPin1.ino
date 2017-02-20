//Globals
int sensorValue;
int distance;

//Pins
int motorPin = 9;
int sonarPin = A5;

void setup() {
  pinMode(sonarPin,INPUT);
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int distance = getDistanceInches();
  
  if (distance < 15) {
    analogWrite(motorPin, 255);
    delay(500);
    analogWrite(motorPin, 0);
    delay(500);
  }
  
  else if (distance < 40) {
    analogWrite(motorPin, 150);
    Serial.println(distance);
  }
  
  else if (distance < 60) {
    analogWrite(motorPin, 100);
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
  
  else {
    analogWrite(motorPin, 0);
  }
}

int getDistanceInches() {
  int inchesRead;
  sensorValue=analogRead(sonarPin);
  delay(50);
  inchesRead = (sensorValue * 0.497);
  return inchesRead;
}

int getDistanceCM() {
  int cm;
  sonarVal = analogRead(sonarPin);
  delay(50);
  cm = (sonarVal * 0.497 * 2.54);
  return cm;
}

