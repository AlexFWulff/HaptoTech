//Just a quick heads up: This code is using the other analog input on the
//Trinket, which happens to be connected to the USB programmer. To upload code
//to the Trinket the pot needs to be centered right in the middle (between the
//three and one markers), otherwise things will get funky.

//Globals
int distance = 0;
int sensorVal = 0;
int sonarVal = 0;
float finalPot = 0;

//Pins
int motorPin = 0;
int sonarPin = 2;
int potPin = 4;

void setup() {
  pinMode(sonarPin, INPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
 distance = getDistanceCM();
 
 float pot = analogRead(2);
 finalPot = pot / 250;
  
  if (distance < (30 * finalPot) ) {
    digitalWrite(motorPin, HIGH);
    delay(100);
    digitalWrite(motorPin, LOW);
    delay(50);
  }
  
  else if (distance < (80 * finalPot) ) {
    digitalWrite(motorPin, HIGH);
    delay(300);
    digitalWrite(motorPin, LOW);
    delay(100);
  }
  
  else if (distance < (120 * finalPot) ) {
    digitalWrite(motorPin, HIGH);
  }
  
  else {
    digitalWrite(motorPin, LOW);
  }
}

int getDistanceCM() {
  int cm;
  sonarVal = analogRead(sonarPin);
  delay(50);
  cm = (sonarVal * 0.497 * 2.54);
  return cm;
}
