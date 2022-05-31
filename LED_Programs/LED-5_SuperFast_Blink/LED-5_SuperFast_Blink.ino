void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(9, HIGH); //INCREASING START
  delay(25);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  delay(25);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(25);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  delay(25);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  delay(25);
  digitalWrite(13, LOW); //INCREASING END
  delay(25);
  digitalWrite(13, HIGH); //DECREASING START
  delay(25);
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  delay(25);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  delay(25);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  delay(25);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  delay(25);
  digitalWrite(9, LOW); //DECREASING END
  delay(25);
}
