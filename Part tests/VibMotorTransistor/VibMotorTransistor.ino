int transistorPin = 6;

 

void setup(){

pinMode(transistorPin, OUTPUT);

}

 

void loop(){

digitalWrite(transistorPin, HIGH);

delay(1000);

digitalWrite(transistorPin, LOW);

delay(1000);

}
