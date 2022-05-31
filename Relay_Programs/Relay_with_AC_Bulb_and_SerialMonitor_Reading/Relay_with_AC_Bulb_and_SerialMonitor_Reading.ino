void setup() {
  pinMode(9, OUTPUT);
  Serial.begin(9600);

  digitalWrite(9, HIGH);
}

void loop() {
  if (Serial.available() == 1) {
    char input = Serial.read();
    if (input == '1') {
      digitalWrite(9, LOW);
      Serial.println("Bulb is On.");
    }
    else if (input == '0') {
      digitalWrite(9, HIGH);
      Serial.println("Bulb is Off.");
    }
  }
}
