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
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (ble_connected()) {
     digitalWrite(13, HIGH);
  } 
    else {
      digitalWrite(13, LOW);
  }
  ble_do_events();
  while(ble_available()) {

    byte data0 = ble_read();
    delay(100);
    Serial.print("Byte rcieved:");
    Serial.println(data0);
    
    if (data0 == 1) {
      analogWrite(9, 28);
      delay(1000);
    }
    
    else if (data0 == 2) {
      analogWrite(9, 50);
      delay(1000);
      Serial.println("YA! It worked!");
    }
    
    else if (data0 == 3) {
      analogWrite(9, 180);
      delay(1000);
    }
    
    else {
      Serial.print("No match for byte value of ");
      Serial.println(data0);
    }
  }
}
    
    
