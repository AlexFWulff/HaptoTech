//Globals
int distance = 0;
int sensorVal = 0;
int sonarVal = 0;
float finalPot = 0;

//Pins
int potPin = 4;
int ledPin = 1;

void setup() {
  pinMode(potPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  
  for (int i = 0; i < 10; i++) {
    float pot = analogRead(2);
    float value = map(pot, 0, 1023, 0, 5);
    finalPot = finalPot + value;
  }
  
  finalPot = finalPot / 10;
  
  if (finalPot > 4) {
    digitalWrite(1, HIGH);
  }
  
  else {
    digitalWrite(1, LOW);
  }
}
