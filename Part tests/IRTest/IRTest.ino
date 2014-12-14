// Sets up IR Sensor
int        pinIR             =   A5  ;

void setup()
{
 // Sets up IR Sensor
 Serial.begin(9600);
}

void loop()
{
  float distance = getDistance();
 // For convertToDistance()
 Serial.print( "Distance: " );
 Serial.println( distance );
 delay( 600 );
}


double getDistance()
{
  double sensorValue       =   0.0 ;
  float distanceFromIR    =   0.0 ;
  sensorValue = analogRead( pinIR ); 
  sensorValue *= .0049;
  Serial.print( "Value: " );
  Serial.println( sensorValue );
  distanceFromIR = 3*pow ( ( sensorValue - 3 ) , 4 ) + 15;
  return distanceFromIR;
}
