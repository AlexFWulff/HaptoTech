float Inch=0.00;
float cm=0.00;
int SonarPin=A5;
int  sensorValue;
void setup(){
pinMode(SonarPin,INPUT);
Serial.begin(9600);
pinMode(13, OUTPUT);
}
void loop(){
sensorValue=analogRead(SonarPin);
delay(50);
Inch= (sensorValue*0.497);
cm=Inch*2.54;
Serial.println(sensorValue);
Serial.print(Inch);
Serial.println("inch");
Serial.print(cm);
Serial.println("cm");
if (Inch < 10) {
  digitalWrite(13, HIGH);
}
else {
 digitalWrite(13, LOW); 
}
delay(100);
}
