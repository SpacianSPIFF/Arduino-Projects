int S1 = 0, S2 = 0, S3 = 0, S4 = 0;
void setup() {
  for (int i = 3; i <= 6; i++)
  {
    pinMode(i, OUTPUT); //Motor pins
  }
  for (int j = 7; j <= 10; j++)
  {
    pinMode(j, INPUT); //Switch pins
  }
  Serial.begin(9600);
}

void loop() {
  S1 = digitalRead(7);
  S2 = digitalRead(8);
  S3 = digitalRead(9);
  S4 = digitalRead(10);
  Serial.print("S1=");
  Serial.println(S1);
  Serial.print("S2=");
  Serial.println(S2);
  Serial.print("S3=");
  Serial.println(S3);
  Serial.print("S4=");
  Serial.println(S4);
  if (S1 == 1)
  {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    Serial.println("The car is moving forward.");
  }
  if (S2 == 1)
  {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    Serial.println("The car is turning left.");
  }
  if (S3 == 1)
  {
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    Serial.println("The car is turning right.");
  }
  if (S4 == 1)
  {
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    Serial.println("The car is moving backward.");
  }
  else if (S1 == 0 || S2 == 0 || S3 == 0 || S4 == 0)
  {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  }
}
