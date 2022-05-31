int Y = 0, X = 0;
void setup() {
  pinMode(A0, INPUT); // Y-Axis
  pinMode(A1, INPUT); //X-Axis
  for (int i = 3; i <= 6; i++)
  {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  Y = analogRead(A0);
  X = analogRead(A1);
  Serial.print("Y=");
  Serial.println(Y);
  Serial.print("X=");
  Serial.println(X);
  if (X <= 1023 and X >= 990 and Y <= 1023 and Y >= 125) //Forward
  {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    Serial.println("The car moves forward");
  }
  if (X <= 1000 and X >= 50 and Y <= 1023 and Y >= 990) //Right
  {
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    Serial.println("The car turns right");
  }
  if (X <= 75 and X >= 0 and Y <= 1023 and Y >= 0) //Reverse
  {
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    Serial.println("The car moves backward");
  }
  if (X <= 1023 and X >= 75 and Y <= 125 and Y >= 0) //Left
  {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    Serial.println("The car turns left");
  }
  if (X <= 520 and X >= 460 and Y <= 550 and Y >= 485) //Stop Car
  {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  }
  delay(125);
}
