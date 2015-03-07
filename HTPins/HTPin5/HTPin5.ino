//Globals
int distance = 0;
int sensorVal = 0;
int sonarVal = 0;

//Pins
int motorPin = 0;
int sonarPin = 2;
int vibPin = 1;

void setup() {
  pinMode(sonarPin, INPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(vibPin, INPUT_PULLUP);
}

void loop() {
 int sensorVal = digitalRead(vibPin);
 
 if (sensorVal == LOW) {
 for (int i = 0; i < 100; i++) {
   
 distance = getDistanceCM();
  if (distance < 30) {
    digitalWrite(motorPin, HIGH);
    delay(100);
    digitalWrite(motorPin, LOW);
    delay(50);
  }
  
  else if (distance < 80) {
    digitalWrite(motorPin, HIGH);
    delay(300);
    digitalWrite(motorPin, LOW);
    delay(100);
  }
  
  else if (distance < 120) {
    digitalWrite(motorPin, HIGH);
  }
  
  else {
    digitalWrite(motorPin, LOW);
  }
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
