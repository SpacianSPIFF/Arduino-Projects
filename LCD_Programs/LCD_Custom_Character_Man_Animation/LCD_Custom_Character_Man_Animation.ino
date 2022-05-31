#include <LiquidCrystal.h>

// Website for graphical character making: https://maxpromer.github.io/LCD-Character-Creator/

// Pin initialization
const int rs = 12, en = 11, d4 = 5, d5 = 6, d6 = 7, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int delayTime = 200;

byte man_idle[] = {
  B00100,
  B01110,
  B00100,
  B01110,
  B10101,
  B00100,
  B01010,
  B01010
};

byte man_crouch[] = {
  B00000,
  B00100,
  B01110,
  B00100,
  B01110,
  B10101,
  B00100,
  B01010
};

byte man_come_up_from_crouch_idle[] = {
  B00100,
  B01110,
  B00100,
  B01110,
  B10101,
  B00100,
  B01010,
  B01010
};

byte man_going_up_middle[] = {
  B00100,
  B01110,
  B00100,
  B11111,
  B00100,
  B00100,
  B01010,
  B01010
};

byte man_went_up[] = {
  B00100,
  B01110,
  B10101,
  B01110,
  B00100,
  B01010,
  B10001,
  B10001
};

byte man_up_middle[] = {
  B00100,
  B01110,
  B00100,
  B11111,
  B00100,
  B01010,
  B10001,
  B10001
};

byte man_crouch_after_coming_down[] = {
  B00000,
  B00100,
  B01110,
  B00100,
  B01110,
  B10101,
  B00100,
  B01010
};

byte man_stand_up_after_jump_idle[] = {
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
  lcd.begin(16, 2);
  lcd.clear();
  // Create a custom character
  lcd.createChar(0, man_idle);
  lcd.createChar(1, man_crouch);
  lcd.createChar(2, man_come_up_from_crouch_idle);
  lcd.createChar(3, man_going_up_middle);
  lcd.createChar(4, man_went_up);
  lcd.createChar(5, man_up_middle);
  lcd.createChar(6, man_crouch_after_coming_down);
  lcd.createChar(7, man_stand_up_after_jump_idle);
  lcd.home();
}

void loop() {
  jump_animation(0);
  jump_animation(1);
  jump_animation(0);
  jump_animation(3);
  jump_animation(4);
  jump_animation(5);
  jump_animation(0);
  jump_animation(1);
}

void jump_animation(int jump_frame) {
  lcd.write(jump_frame);
  delay(delayTime);
  lcd.clear();
}
