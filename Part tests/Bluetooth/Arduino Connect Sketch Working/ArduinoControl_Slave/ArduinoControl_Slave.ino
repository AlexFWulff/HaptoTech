#include <RBL_nRF8001.h>
#include <boards.h>
#include <ble.h>
#include <SPI.h>



void setup() {
  SPI.setDataMode(SPI_MODE0);
  SPI.setBitOrder(LSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  SPI.begin();
  ble_begin();
  pinMode(13, OUTPUT);
}

void loop() {
  if (ble_connected()) {
     digitalWrite(13, HIGH);
  } 
    else {
      digitalWrite(13, LOW);
  }
  ble_do_events();
}
