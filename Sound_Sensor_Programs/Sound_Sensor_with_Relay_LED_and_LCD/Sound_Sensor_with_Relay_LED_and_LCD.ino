#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 6, d6 = 7, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int noise_val = 0;
int noise_sampling = 100;
bool is_on =  false;

void setup() {
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  for (int i = 0; i < noise_sampling; i++) {
    int noise_reading = analogRead(A0);
    noise_val += noise_reading;
  }
  noise_val /= noise_sampling;

  lcd.begin(16, 2);
  lcd.clear();
  
  digitalWrite(9, is_on);
}

void loop() {
  int mic_reading = analogRead(A0);
  mic_reading -= noise_val;
  if (mic_reading < 0) {
    mic_reading = 0;
  }
  Serial.println(mic_reading);
  if (mic_reading > 10) {
    if (is_on) {
      is_on = false;
      lcd.print("LED is OFF.");
    }
    else {
      is_on = true;
      lcd.print("LED is ON.");
    }
    digitalWrite(9, is_on);
  }
}
