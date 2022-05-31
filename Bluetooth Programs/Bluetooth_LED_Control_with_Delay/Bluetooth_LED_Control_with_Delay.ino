// Define variables
int delay_dur = 200;   // initial delay
bool state = false;    // Overall state 
String value;          // variable to hold readString

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()){
    value = Serial.readString();
    value.trim();
    if (value == "TURNON") {
      state = true;
    }
    else if (value == "TURNOFF") {
      state = false;
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if (value.startsWith("delay")) {
        delay_dur = value.substring(6).toInt();
        Serial.println("Delay is changed to " + String(delay_dur));
    }
  }
  if (state) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(delay_dur);
    digitalWrite(LED_BUILTIN, LOW);
    delay(delay_dur);
  }
}
