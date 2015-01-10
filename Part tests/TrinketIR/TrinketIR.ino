//A Note ABout the pins: I KNOW THAT IM ALANLOG READING FROM PIN WHEN WHEN THE
//SENSOR IS DECLARED AS TWO BUT YOU DON'T F$%@ING TOUCH THAT SH%T BECUASE 
//YOU'RE SUPPOSED TO USE THE ANALOG NUMBER WHEN READING, AND PIN 2 IS DECLARED AS
//A1, OR 1 TO THE MOTHERFUCKING ATTINY BITCH-ASS SHITTY CHIP THAT TOOK ME FOUR
//FUCKING HOURS TO SOLVE THANK YOU VERY FUNCKING MUCH NOW I'M OFF TO FIX MY
//OTHER MODELS THAT I THOUGHT WERE DEFECTIVE BECAUSE OF THIS MOTHERF#$%ING CHIP

//pin setups: ir -> #2 (read the bove message) led -> #0

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
