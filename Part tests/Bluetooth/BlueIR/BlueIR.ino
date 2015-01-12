#include <SPI.h>
#include <boards.h>
#include <RBL_nRF8001.h>

int sensor = A5;

void setup() {
  pinMode(sensor, INPUT);
  // Set your BLE Shield name here, max. length 10
  ble_set_name("ArduSight");
  
  // Init. and start BLE library.
  ble_begin();
  
  // Enable serial debug
  Serial.begin(9600);

}

unsigned char buf[16] = {0};
unsigned char len = 0;

void loop()
{
  if ( ble_connected() ) {
    float a = 16;
    sendMyInt(a);
    ble_do_events();
    delay(200);
    clearLabel();
    ble_do_events();
  }
  ble_do_events();
}

void sendMyInt(int myInt) {
  char b[4];
  
//  myInt = myInt * 10;

  String str;  

  str=String(myInt);

  str.toCharArray(b,4);
  
  for (int i = 0; i < 3; i++) {
    char toPrint = b[i];
    ble_write(toPrint);
  }
}

void clearLabel() {
  int clearString = 33;
  char excalamtion = clearString;
  ble_write(excalamtion);
}

int getDistance() {
  float suppliedVoltage = 3.3;
               
  // read the input on analog pin 0:
  float sensorValue = analogRead(sensor);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float ReadVoltage = sensorValue * (suppliedVoltage / 1023.0);
  float voltage = map(ReadVoltage, 0, suppliedVoltage, suppliedVoltage, 0);
  
  Serial.println(voltage);
  
  int distance = voltage * 11;
  
  return distance;
}
