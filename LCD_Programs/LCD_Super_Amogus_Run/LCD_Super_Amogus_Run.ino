#include <LiquidCrystal.h>

// Website for graphical character making: https://maxpromer.github.io/LCD-Character-Creator/

// Pin initialization
const int rs = 12, en = 11, d4 = 5, d5 = 6, d6 = 7, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int delayTime = 200;
int pos = 14;
bool isjump = false;
bool gameOver = false;

byte amogus[] = {
  B00000,
  B01110,
  B10001,
  B10001,
  B11111,
  B11011,
  B11011,
  B00000
};

byte obstacle[] = {
  B00000,
  B00000,
  B11111,
  B11111,
  B01110,
  B01110,
  B01110,
  B01110
};

void setup() {
  pinMode(9, INPUT);
  
  lcd.begin(16, 2);
  lcd.clear();
  lcd.createChar(0, amogus);
  lcd.createChar(1, obstacle);
  lcd.home();
}

void loop() {
  lcd.clear();

  while (!gameOver) {
    lcd.clear();

    isjump = digitalRead(9);
    
    if(isjump == false) {
      lcd.setCursor(1, 1);
      lcd.write(byte(0));
    }
    else if(isjump == true) {
      lcd.setCursor(1, 0);
      lcd.write(byte(0));
    }
    
    if (pos >= 2) {
      lcd.setCursor(pos, 1);
      lcd.write(byte(1));
      pos = pos - 1;
    }
    
    if(isjump == true && pos == 1) {
      lcd.setCursor(pos, 1);
      lcd.write(byte(1));
    }
    
    if(isjump == false && pos == 1) {
      gameOver = true;
    }
    
    if(pos == 0) {
      pos = 14;
    }
    
    delay(delayTime);
  }

  lcd.print("Game Over!");
}

void updatePlayerPos() {

}

void updateObstaclePos() {
  
}
