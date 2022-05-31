String ps;
void setup() {
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  Serial.print("Enter the password=");
}

void loop() {
  if (Serial.available())
  {
    ps = Serial.readStringUntil('\n');
    if (ps.equals("74"))
    {
      Serial.println(ps);
      digitalWrite(3, HIGH);
      Serial.println("The password is correct.");
      for (int i = 5; i > 0; i--)
      {
        Serial.print("The LED will turn OFF in ");
        Serial.println(i);
        if (i == 1)
        {
          delay(1000);
          digitalWrite(3, LOW);
          Serial.println("The LED is OFF.");
        }
        delay(1000);
      }
    }
  }
}
