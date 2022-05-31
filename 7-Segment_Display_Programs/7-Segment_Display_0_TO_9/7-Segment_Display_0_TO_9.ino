int i=3;
void setup() {
  for(int i=3;i<=9;i++)
  {
    pinMode(i,OUTPUT);
  }
}

void loop() {
  digitalWrite(4,HIGH); //ZERO
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  delay(500);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(6,HIGH); //ONE
  digitalWrite(9,HIGH);
  delay(500);
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
  digitalWrite(3,HIGH); //TWO
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  delay(500);
  digitalWrite(3,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(5,HIGH); //THREE
  digitalWrite(6,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(8,HIGH);
  delay(500);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(3,LOW);
  digitalWrite(9,LOW);
  digitalWrite(8,LOW);
  digitalWrite(4,HIGH); //FOUR
  digitalWrite(3,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(9,HIGH);
  delay(500);
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
  digitalWrite(5,HIGH); //FIVE
  digitalWrite(4,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(8,HIGH);
  delay(500);
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
  digitalWrite(9,LOW);
  digitalWrite(8,LOW);
  digitalWrite(5,HIGH); //SIX
  digitalWrite(4,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  delay(500);
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(5,HIGH); //SEVEN
  digitalWrite(6,HIGH);
  digitalWrite(9,HIGH);
  delay(500);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
  digitalWrite(3,HIGH); //EIGHT
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  delay(500);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(3,HIGH); //NINE
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  delay(500);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
}
