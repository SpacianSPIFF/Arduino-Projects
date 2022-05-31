String input;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {
  if(Serial.available() > 0)
  {
    input = Serial.readString();
    input.trim();
    Serial.println(input);
    if(input == "on") {
      digitalWrite(13, HIGH);
    }
    else if(input == "off") {
      digitalWrite(13, LOW);
    }
  }
}
