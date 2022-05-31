String incomingString;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingString = Serial.readString();

    // incomingString.remove(incomingString.length() - 1);
    incomingString.trim();  // Strips of whitespace
    
    Serial.println("String received: " + incomingString);
  }
}
