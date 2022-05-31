int ones = 0, tens = 0,u;
void setup() {
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  Serial.print("Enter the password=");
}

void loop() {
  if (Serial.available()>0)
  {
    u = Serial.read();
    Serial.println(u);
    ones = u % 10; //XY % 10 = Y
    tens = u / 10; //XY / 10 = X
    if (ones == 3 && tens == 6) //Password = 63
    {
      digitalWrite(3, HIGH);
      Serial.println("Correct password.");
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
    else if (ones != 3 || tens != 6)
    {
      Serial.println("Wrong password.");
    }
  }
}
