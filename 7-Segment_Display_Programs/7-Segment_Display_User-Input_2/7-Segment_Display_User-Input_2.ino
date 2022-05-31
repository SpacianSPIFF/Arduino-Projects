char k;
void setup() {
  for (int i = 3; i < 10; i++) {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}
void TheNum(char num) {
  switch (num) {
    case '0' : //ZERO 0
      digitalWrite(3, 0);
      digitalWrite(4, 1);
      digitalWrite(5, 1);
      digitalWrite(6, 1);
      digitalWrite(7, 1);
      digitalWrite(8, 1);
      digitalWrite(9, 1);
      break;
    case '1' : //ONE 1
      digitalWrite(3, 0);
      digitalWrite(4, 0);
      digitalWrite(5, 0);
      digitalWrite(6, 1);
      digitalWrite(7, 0);
      digitalWrite(8, 0);
      digitalWrite(9, 1);
      break;
    case '2' : //TWO 2
      digitalWrite(3, 1);
      digitalWrite(4, 0);
      digitalWrite(5, 1);
      digitalWrite(6, 1);
      digitalWrite(7, 1);
      digitalWrite(8, 1);
      digitalWrite(9, 0);
      break;
    case '3' : //THREE 3
      digitalWrite(3, 1);
      digitalWrite(4, 0);
      digitalWrite(5, 1);
      digitalWrite(6, 1);
      digitalWrite(7, 0);
      digitalWrite(8, 1);
      digitalWrite(9, 1);
      break;
    case '4' : //FOUR 4
      digitalWrite(3, 1);
      digitalWrite(4, 1);
      digitalWrite(5, 0);
      digitalWrite(6, 1);
      digitalWrite(7, 0);
      digitalWrite(8, 0);
      digitalWrite(9, 1);
      break;
    case '5' : //FIVE 5
      digitalWrite(3, 1);
      digitalWrite(4, 1);
      digitalWrite(5, 1);
      digitalWrite(6, 0);
      digitalWrite(7, 0);
      digitalWrite(8, 1);
      digitalWrite(9, 1);
      break;
    case '6' : //SIX 6
      digitalWrite(3, 1);
      digitalWrite(4, 1);
      digitalWrite(5, 1);
      digitalWrite(6, 0);
      digitalWrite(7, 1);
      digitalWrite(8, 1);
      digitalWrite(9, 1);
      break;
    case '7' : //SEVEN 7
      digitalWrite(3, 0);
      digitalWrite(4, 0);
      digitalWrite(5, 1);
      digitalWrite(6, 1);
      digitalWrite(7, 0);
      digitalWrite(8, 0);
      digitalWrite(9, 1);
      break;
    case '8' : //EIGHT 8
      digitalWrite(3, 1);
      digitalWrite(4, 1);
      digitalWrite(5, 1);
      digitalWrite(6, 1);
      digitalWrite(7, 1);
      digitalWrite(8, 1);
      digitalWrite(9, 1);
      break;
    case '9' : //NINE 9
      digitalWrite(3, 1);
      digitalWrite(4, 1);
      digitalWrite(5, 1);
      digitalWrite(6, 1);
      digitalWrite(7, 0);
      digitalWrite(8, 1);
      digitalWrite(9, 1);
      break;
  }
}
void loop() {
  if (Serial.available() > 0)
  {
    k = Serial.read();
    TheNum(k);
    Serial.print("The Number is=");
    Serial.println(k);
    delay(1000);
  }
}
