int sonarVal = 0;
int distance = 0;

void setup() {
  pinMode(2, INPUT);
  pinMode(1, INPUT);
  pinMode(0, OUTPUT);
}

void loop() {
 digitalWrite(0, HIGH);
 int sensorVal = digitalRead(1);
   if (sensorVal == HIGH) {
     for (int i = 0; i < 100; i++) {
       distance = getDistanceCM();
       digitalWrite(0, LOW);
     }
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
