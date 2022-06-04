#include "LedControl.h"

int DIN = 10;
int CS =  9;
int CLK = 8;

int delayTime = 54;

LedControl lc = LedControl(DIN, CLK, CS, 1);

byte arrow_up1[8] = {B00011000, B00111100, B01111110, B11111111, B00011000, B00011000, B00011000, B00011000};
byte arrow_up2[8] = {B00111100, B01111110, B11111111, B00011000, B00011000, B00011000, B00011000, B00000000};
byte arrow_up3[8] = {B01111110, B11111111, B00011000, B00011000, B00011000, B00011000, B00000000, B00011000};
byte arrow_up4[8] = {B11111111, B00011000, B00011000, B00011000, B00011000, B00000000, B00011000, B00111100};
byte arrow_up5[8] = {B00011000, B00011000, B00011000, B00011000, B00000000, B00011000, B00111100, B01111110};
byte arrow_up6[8] = {B00011000, B00011000, B00011000, B00000000, B00011000, B00111100, B01111110, B11111111};
byte arrow_up7[8] = {B00011000, B00011000, B00000000, B00011000, B00111100, B01111110, B11111111, B00011000};
byte arrow_up8[8] = {B00011000, B00000000, B00011000, B00111100, B01111110, B11111111, B00011000, B00011000};
byte arrow_up9[8] = {B00000000, B00011000, B00111100, B01111110, B11111111, B00011000, B00011000, B00011000};

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 1);
  lc.clearDisplay(0);
}

void loop() {
  printByte(arrow_up1);
  delay(delayTime);
  printByte(arrow_up2);
  delay(delayTime);
  printByte(arrow_up3);
  delay(delayTime);
  printByte(arrow_up4);
  delay(delayTime);
  printByte(arrow_up5);
  delay(delayTime);
  printByte(arrow_up6);
  delay(delayTime);
  printByte(arrow_up7);
  delay(delayTime);
  printByte(arrow_up8);
  delay(delayTime);
  printByte(arrow_up9);
  delay(delayTime);
}

void printByte(byte character[]) {
  for(int i = 0; i < 8; i++) {
    lc.setRow(0, i, character[i]);
  }
}
