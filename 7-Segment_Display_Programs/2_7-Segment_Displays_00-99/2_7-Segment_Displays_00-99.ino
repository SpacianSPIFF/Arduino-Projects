void setup() {
  for (int pm = 0; pm <= 13; pm++) {
    pinMode(pm, OUTPUT);
  }
}

void D2() {
  digitalWrite(7, 0); //D2 ZERO 0
  digitalWrite(8, 1);
  digitalWrite(9, 1);
  digitalWrite(10, 1);
  digitalWrite(11, 1);
  digitalWrite(12, 1);
  digitalWrite(13, 1);
  delay(1000);
  digitalWrite(7, 0); //D2 ONE 1
  digitalWrite(8, 0);
  digitalWrite(9, 0);
  digitalWrite(10, 1);
  digitalWrite(11, 0);
  digitalWrite(12, 0);
  digitalWrite(13, 1);
  delay(1000);
  digitalWrite(7, 1); //D2 TWO 2
  digitalWrite(8, 0);
  digitalWrite(9, 1);
  digitalWrite(10, 1);
  digitalWrite(11, 1);
  digitalWrite(12, 1);
  digitalWrite(13, 0);
  delay(1000);
  digitalWrite(7, 1); //D2 THREE 3
  digitalWrite(8, 0);
  digitalWrite(9, 1);
  digitalWrite(10, 1);
  digitalWrite(11, 0);
  digitalWrite(12, 1);
  digitalWrite(13, 1);
  delay(1000);
  digitalWrite(7, 1); //D2 FOUR 4
  digitalWrite(8, 1);
  digitalWrite(9, 0);
  digitalWrite(10, 1);
  digitalWrite(11, 0);
  digitalWrite(12, 0);
  digitalWrite(13, 1);
  delay(1000);
  digitalWrite(7, 1); //D2 FIVE 5
  digitalWrite(8, 1);
  digitalWrite(9, 1);
  digitalWrite(10, 0);
  digitalWrite(11, 0);
  digitalWrite(12, 1);
  digitalWrite(13, 1);
  delay(1000);
  digitalWrite(7, 1); //D2 SIX 6
  digitalWrite(8, 1);
  digitalWrite(9, 1);
  digitalWrite(10, 0);
  digitalWrite(11, 1);
  digitalWrite(12, 1);
  digitalWrite(13, 1);
  delay(1000);
  digitalWrite(7, 0); //D2 SEVEN 7
  digitalWrite(8, 0);
  digitalWrite(9, 1);
  digitalWrite(10, 1);
  digitalWrite(11, 0);
  digitalWrite(12, 0);
  digitalWrite(13, 1);
  delay(1000);
  digitalWrite(7, 1); //D2 EIGHT 8
  digitalWrite(8, 1);
  digitalWrite(9, 1);
  digitalWrite(10, 1);
  digitalWrite(11, 1);
  digitalWrite(12, 1);
  digitalWrite(13, 1);
  delay(1000);
  digitalWrite(7, 1); //D2 NINE 9
  digitalWrite(8, 1);
  digitalWrite(9, 1);
  digitalWrite(10, 1);
  digitalWrite(11, 0);
  digitalWrite(12, 1);
  digitalWrite(13, 1);
  delay(1000);
}

void loop() {
  digitalWrite(0, 0); //D1 ZERO 0
  digitalWrite(1, 1);
  digitalWrite(2, 1);
  digitalWrite(3, 1);
  digitalWrite(4, 1);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  D2();
  digitalWrite(0, 0); //D1 ONE 1
  digitalWrite(1, 0);
  digitalWrite(2, 0);
  digitalWrite(3, 1);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  D2();
  digitalWrite(0, 1); //D1 TWO 2
  digitalWrite(1, 0);
  digitalWrite(2, 1);
  digitalWrite(3, 1);
  digitalWrite(4, 1);
  digitalWrite(5, 1);
  digitalWrite(6, 0);
  D2();
  digitalWrite(0, 1); //D1 THREE 3
  digitalWrite(1, 0);
  digitalWrite(2, 1);
  digitalWrite(3, 1);
  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  D2();
  digitalWrite(0, 1); //D1 FOUR 4
  digitalWrite(1, 1);
  digitalWrite(2, 0);
  digitalWrite(3, 1);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  D2();
  digitalWrite(0, 1); //D1 FIVE 5
  digitalWrite(1, 1);
  digitalWrite(2, 1);
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  D2();
  digitalWrite(0, 1); //D1 SIX 6
  digitalWrite(1, 1);
  digitalWrite(2, 1);
  digitalWrite(3, 0);
  digitalWrite(4, 1);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  D2();
  digitalWrite(0, 0); //D1 SEVEN 7
  digitalWrite(1, 0);
  digitalWrite(2, 1);
  digitalWrite(3, 1);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  D2();
  digitalWrite(0, 1); //D1 EIGHT 8
  digitalWrite(1, 1);
  digitalWrite(2, 1);
  digitalWrite(3, 1);
  digitalWrite(4, 1);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  D2();
  digitalWrite(0, 1); //D1 NINE 9
  digitalWrite(1, 1);
  digitalWrite(2, 1);
  digitalWrite(3, 1);
  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  D2();
}
