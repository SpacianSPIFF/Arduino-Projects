int kpval;
char n;
void setup() {
  pinMode(A0,INPUT);
  for (int i=3;i<=9;i++)
  {
    pinMode(i,OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  kpval=analogRead(A0);
  Serial.println(kpval);
  if(kpval<=283 and kpval>=274) //ZERO 0
  {
    n=0;
    TheNum(n);
    Serial.println("The seven segment display shows:" + n);
  }
  if(kpval<=926 and kpval>=923) //ONE 1
  {
    n=1;
    TheNum(n);
    Serial.println("The seven segment display shows:" + n);
  }
  if(kpval<=767 and kpval>=764) //TWO 2
  {
    n=2;
    TheNum(n);
    Serial.println("The seven segment display shows:" + n);
  }
  if(kpval<=907 and kpval>=904) //THREE 3
  {
    n=3;
    TheNum(n);
    Serial.println("The seven segment display shows:" + n);
  }
  if(kpval<=878 and kpval>=875) //FOUR 4
  {
    n=4;
    TheNum(n);
    Serial.println("The seven segment display shows:" + n);
  }
  if(kpval<=734 and kpval>=731) //FIVE 5
  {
    n=5;
    TheNum(n);
    Serial.println("The seven segment display shows:" + n);
  }
  if(kpval<=861 and kpval>=858) //SIX 6
  {
    n=6;
    TheNum(n);
    Serial.println("The seven segment display shows:" + n);
  }
  if(kpval<=638 and kpval>=631) //SEVEN 7
  {
    n=7;
    TheNum(n);
    Serial.println("The seven segment display shows:" + n);
  }
  if(kpval<=558 and kpval>=552) //EIGHT 8
  {
    n=8;
    TheNum(n);
    Serial.println("The seven segment display shows:" + n);
  }
  if(kpval<=632 and kpval>=620) //NINE 9
  {
    n=9;
    TheNum(n);
    Serial.println("The seven segment display shows:" + n);
  }
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
