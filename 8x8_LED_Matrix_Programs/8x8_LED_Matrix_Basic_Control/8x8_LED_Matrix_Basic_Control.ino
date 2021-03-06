// LED 8x8 Matrix Display

// For Custom Character Generator: http://jorydotcom.github.io/matrix-emoji
// LedControl library: https://github.com/wayoda/LedControl
// LedControl docs: http://wayoda.github.io/LedControl/

// Arduino UNO SPI Pins: 13 -> SCK[Serial Clock](CLK); 12 -> MISO[Master In Slave Out]; 11 -> MOSI[Master Out Slave In](DIN); 10 -> SS[Slave Select]

#include "LedControl.h"
int DIN = 10;
int CS =  9;
int CLK = 8;

LedControl lc = LedControl(DIN, CLK, CS, 1);

// Facial Expression
byte smile[8] =   {0x3C, 0x42, 0xA5, 0x81, 0xA5, 0x99, 0x42, 0x3C};
byte neutral[8] = {0x3C, 0x42, 0xA5, 0x81, 0xBD, 0x81, 0x42, 0x3C};
byte sad[8] = {0x3C, 0x42, 0xA5, 0x81, 0x99, 0xA5, 0x42, 0x3C};

// Arrow
byte arrow_up[8] = {0x18, 0x3C, 0x7E, 0xFF, 0x18, 0x18, 0x18, 0x18};
byte arrow_down[8] = {0x18, 0x18, 0x18, 0x18, 0xFF, 0x7E, 0x3C, 0x18};

// Alternate Pattern
byte d1[8] = {0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55};
byte d2[8] = {0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA};

// Moving car
byte b1[8] = {0x00, 0x00, 0x00, 0x00, 0x18, 0x3C, 0x18, 0x3C};
byte b2[8] = {0x00, 0x00, 0x00, 0x18, 0x3C, 0x18, 0x3C, 0x00};
byte b3[8] = {0x00, 0x00, 0x18, 0x3C, 0x18, 0x3C, 0x00, 0x00};
byte b4[8] = {0x00, 0x18, 0x3C, 0x18, 0x3C, 0x00, 0x00, 0x00};
byte b5[8] = {0x18, 0x3C, 0x18, 0x3C, 0x00, 0x00, 0x00, 0x00};
byte b6[8] = {0x3C, 0x18, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x18};
byte b7[8] = {0x18, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x18, 0x3C};
byte b8[8] = {0x3C, 0x00, 0x00, 0x00, 0x00, 0x18, 0x3C, 0x18};

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 1);  // Ranges from 0 to 15
  lc.clearDisplay(0);
}

void loop() {
  // Moving car
  printByte(b1);
  delay(75);
  printByte(b2);
  delay(75);
  printByte(b3);
  delay(75);
  printByte(b4);
  delay(75);
  printByte(b5);
  delay(75);
  printByte(b6);
  delay(75);
  printByte(b7);
  delay(75);
  printByte(b8);
  delay(100);
  
  // Alternate pattern
  printByte(d1);
  delay(1000);
  printByte(d2);
  delay(1000);
  
  // Arrow
  printByte(arrow_up);
  delay(1500);
  printByte(arrow_down);
  delay(1500);
  
  // Facial Expression
  printByte(smile);
  delay(1000);
  printByte(neutral);
  delay(1000);
  printByte(sad);
  delay(1000);
}

void printByte(byte character[]) {
  for(int i = 0; i < 8; i++) {
    lc.setRow(0, i, character[i]);
  }
}
