int sonarPin=A5;
int sensorValue;
int distance;

void setup(){
  pinMode(sonarPin,INPUT);
  pinMode(13, OUTPUT);
}

void loop(){
  distance = getDistanceInches();
  if (distance < 20) {
    digitalWrite(13, HIGH);
  }
   else {
    digitalWrite(13, LOW);
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
  int inchesRead;
  int cm;
  sensorValue = analogRead(sonarPin);
  delay(50);
  inchesRead = (sensorValue * 0.497);
  cm = inchesRead * 2.54;
  return cm;
}


