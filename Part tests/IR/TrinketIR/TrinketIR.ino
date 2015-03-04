int sensor = 2;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(0, OUTPUT);
}

void loop() {
  int value = analogRead(1);
  int inter = map(value, 127, 860, 860, 127);
  if (final< 800) {
    digitalWrite(0, HIGH);
  }
  
  else {
    digitalWrite(0, LOW);
  }
}
