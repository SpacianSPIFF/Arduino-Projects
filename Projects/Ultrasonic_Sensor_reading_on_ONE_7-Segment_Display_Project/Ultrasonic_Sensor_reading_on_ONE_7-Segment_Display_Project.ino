const int trig = 2, echo = 3;
float CF = 1;
int duration = 0, distance = 0;
void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  for (int pm = 4; pm <= 10; pm++)
  {
    pinMode(pm, OUTPUT);
  }
  Serial.begin(9600);
  Serial.println("E on the seven-segment display means:ERROR");
}

void loop() {
  digitalWrite(2, LOW);
  delayMicroseconds(2);
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);
  duration = pulseIn(3, HIGH);
  distance = (0.034 * duration) / 2;
  distance = distance * CF;
  Serial.print("Distance=");
  Serial.print(distance);
  Serial.println("cm");
  if (distance <= 9)
  {
    sevseg(distance);
  }
  else
  {
    digitalWrite(4, 1);
    digitalWrite(5, 1);
    digitalWrite(6, 1);
    digitalWrite(7, 0);
    digitalWrite(8, 1);
    digitalWrite(9, 1);
    digitalWrite(10, 0);
  }
  delay(125);
}

void sevseg(int x)
{
  if (x == 0) //ZERO 0
  {
    digitalWrite(4, 0);
    digitalWrite(5, 1);
    digitalWrite(6, 1);
    digitalWrite(7, 1);
    digitalWrite(8, 1);
    digitalWrite(9, 1);
    digitalWrite(10, 1);
  }
  if (x == 1) //ONE 1
  {
    digitalWrite(4, 0);
    digitalWrite(5, 0);
    digitalWrite(6, 0);
    digitalWrite(7, 1);
    digitalWrite(8, 0);
    digitalWrite(9, 0);
    digitalWrite(10, 1);
  }
  if (x == 2) //TWO 2
  {
    digitalWrite(4, 1);
    digitalWrite(5, 0);
    digitalWrite(6, 1);
    digitalWrite(7, 1);
    digitalWrite(8, 1);
    digitalWrite(9, 1);
    digitalWrite(10, 0);
  }
  if (x == 3) //THREE 3
  {
    digitalWrite(4, 1);
    digitalWrite(5, 0);
    digitalWrite(6, 1);
    digitalWrite(7, 1);
    digitalWrite(8, 0);
    digitalWrite(9, 1);
    digitalWrite(10, 1);
  }
  if (x == 4) //FOUR 4
  {
    digitalWrite(4, 1);
    digitalWrite(5, 1);
    digitalWrite(6, 0);
    digitalWrite(7, 1);
    digitalWrite(8, 0);
    digitalWrite(9, 0);
    digitalWrite(10, 1);
  }
  if (x == 5) //FIVE 5
  {
    digitalWrite(4, 1);
    digitalWrite(5, 1);
    digitalWrite(6, 1);
    digitalWrite(7, 0);
    digitalWrite(8, 0);
    digitalWrite(9, 1);
    digitalWrite(10, 1);
  }
  if (x == 6) //SIX 6
  {
    digitalWrite(4, 1);
    digitalWrite(5, 1);
    digitalWrite(6, 1);
    digitalWrite(7, 0);
    digitalWrite(8, 1);
    digitalWrite(9, 1);
    digitalWrite(10, 1);
  }
  if (x == 7) //SEVEN 7
  {
    digitalWrite(4, 0);
    digitalWrite(5, 0);
    digitalWrite(6, 1);
    digitalWrite(7, 1);
    digitalWrite(8, 0);
    digitalWrite(9, 0);
    digitalWrite(10, 1);
  }
  if (x == 8) //EIGHT 8
  {
    digitalWrite(4, 1);
    digitalWrite(5, 1);
    digitalWrite(6, 1);
    digitalWrite(7, 1);
    digitalWrite(8, 1);
    digitalWrite(9, 1);
    digitalWrite(10, 1);
  }
  if (x == 9) //NINE 9
  {
    digitalWrite(4, 1);
    digitalWrite(5, 1);
    digitalWrite(6, 1);
    digitalWrite(7, 1);
    digitalWrite(8, 0);
    digitalWrite(9, 1);
    digitalWrite(10, 1);
  }
}
