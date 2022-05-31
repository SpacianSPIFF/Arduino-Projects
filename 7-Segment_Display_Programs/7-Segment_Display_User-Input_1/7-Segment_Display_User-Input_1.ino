char a;
void setup() {
  for(int i=3;i<10;i++)
  {
    pinMode(i,OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  for(int j=3;j<10;j++)
  {
    digitalWrite(j,LOW);
  }
  if(Serial.available()>0)
  {
    a=Serial.read();
    Num(a);
    Serial.print("The number is=");
    Serial.println(a);
    delay(1000);
  }
}
void Num(char n)
{
  switch(n)
  {
    case '0': //ZERO 0
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    break;
    case '1': //ONE 1
    digitalWrite(6,HIGH);
    digitalWrite(9,HIGH);
    break;
    case '2': //TWO 2
    digitalWrite(3,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    break;
    case '3': //THREE 3
    digitalWrite(3,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    break;
    case '4': //FOUR 4
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(9,HIGH);
    break;
    case '5' : //FIVE 5
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    break;
    case '6' : //SIX 6
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    break;
    case '7' : //SEVEN 7
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(9,HIGH);
    break;
    case '8' : //EIGHT 8
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    break;
    case '9' : //NINE 9
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    break;
  }
}
