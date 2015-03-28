#include <SPI.h>
#include <boards.h>
#include <RBL_nRF8001.h>

int sensor = A5;

void setup() {
  pinMode(sensor, INPUT);
  // Set your BLE Shield name here, max. length 10
  ble_set_name("HTBlue");
  
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
    int a = getDistance();
    sendMyInt(a);
    ble_do_events();
    delay(300);
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
  
  for (int i = 0; i < 2; i++) {
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
  //Calibrated for 3.3 V
  int sensorValue = analogRead(sensor);
//  int distance = 48.223 * pow(2.7182818284, (-0.004*sensorValue));
  int distance = 65.223 * pow(2.7182818284, (-0.004*sensorValue));
  return distance;
}

int getDistance5v() {
  //Calibrated for 5.0 V
  int sensorValue = analogRead(sensor);
  int distance = 91566 * pow(sensorValue, -1.5595);
  return distance;
}
