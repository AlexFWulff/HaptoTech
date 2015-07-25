void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

float finalPot = 0;

void loop() {
//  
//  for (int i = 0; i < 10; i++) {
//    float pot = analogRead(A0);
//    float value = map(pot, 0, 1023, 0, 5);
//    finalPot = finalPot + value;
//  }
//  
//  finalPot = finalPot / 10;

   float pot = analogRead(A0);
   float value = pot / 250;
  
  Serial.println(value);
  delay(100);
}
