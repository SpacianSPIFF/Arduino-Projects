int X = 0, Y = 0, K = 0;
void setup() {
  pinMode(3, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop() {
  Y = analogRead(A0);
  X = analogRead(A1);
  K = digitalRead(3);
  Serial.println("X=" + String(X));
  Serial.println("Y=" + String(Y));
  Serial.println("K=" + String(K));

  delay(300);
}
