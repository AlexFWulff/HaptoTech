int sensor = A5;

void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  double d = getDistance();
  delay(500);
}

int getDistance() {
  //Calibrated for 3.3 V
  int sensorValue = analogRead(sensor);
  
  Serial.println(sensorValue);
}
