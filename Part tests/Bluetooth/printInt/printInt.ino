#include <SPI.h>
#include <boards.h>
#include <RBL_nRF8001.h>

void setup()
{  
  // Default pins set to 9 and 8 for REQN and RDYN
  // Set your REQN and RDYN here before ble_begin() if you need
  //ble_set_pins(3, 2);
  
  // Set your BLE Shield name here, max. length 10
  //ble_set_name("My Name");
  
  // Init. and start BLE library.
  ble_begin();
  
  // Enable serial debug
  Serial.begin(57600);

}

unsigned char buf[16] = {0};
unsigned char len = 0;

void loop()
{
  if ( ble_connected() ) {
    int a = 12;
    sendMyInt(a);
    ble_do_events();
    delay(1000);
    clearLabel();
    ble_do_events();
  }
  ble_do_events();
}

void sendMyInt(int myInt) {
  char b[4];

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
