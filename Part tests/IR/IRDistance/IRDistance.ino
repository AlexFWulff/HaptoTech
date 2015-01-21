int sensor = A5;

void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  double d = getDistance5v();
  delay(500);
}

int getDistance() {
  //Calibrated for 3.3 V
  int sensorValue = analogRead(sensor);
  int distance = 48.223 * pow(2.7182818284, (-0.004*sensorValue));
  Serial.println(distance);
}

int getDistance5v() {
  //Calibrated for 5.0 V
  int sensorValue = analogRead(sensor);
  int distance = 91566 * pow(sensorValue, -1.5595);
  Serial.println(distance);
}
