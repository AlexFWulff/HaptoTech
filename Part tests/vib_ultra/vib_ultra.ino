int sonarVal = 0;
int distance = 0;

void setup() {
  pinMode(2, INPUT);
  pinMode(1, OUTPUT);
  pinMode(0, OUTPUT);
}

void loop() {
  distance = getDistanceCM();
  if (distance > 150) {
    digitalWrite(0, HIGH);
  }
  
  else {
     digitalWrite(0, LOW);
  }
}

int getDistanceCM() {
  int inchesRead;
  int cm;
  sonarVal = analogRead(1);
  delay(50);
  inchesRead = (sonarVal * 0.497);
  cm = inchesRead * 2.54;
  return cm;
}
