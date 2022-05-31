#include <LiquidCrystal.h>

// Website https://maxpromer.github.io/LCD-Character-Creator/

// Pin initialisation
const int rs = 12, en = 11, d4 = 5, d5 = 6, d6 = 7, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte man[] = {
  B00100,
  B01110,
  B00100,
  B01110,
  B10101,
  B00100,
  B01010,
  B01010
};

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.clear();
  // Create a custom character
  lcd.createChar(0, man);
  lcd.home();
}

void loop() {
  lcd.write(byte(0));
  lcd.clear();
}
