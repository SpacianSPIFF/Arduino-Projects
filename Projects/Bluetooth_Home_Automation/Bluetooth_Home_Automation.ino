String read_input, input;
bool bt_state = false;
bool fan_state = false, bulb_state = false, tubelight_state = false;

// Relay has HIGH as OFF and LOW as ON.

void setup() {
  pinMode(4, OUTPUT);  // Mode Relay Pin
  pinMode(5, OUTPUT);  // Fan Relay Pin
  pinMode(6, OUTPUT);  // Bulb Relay Pin
  pinMode(7, OUTPUT);  // Tubelight Relay Pin

  // Turn OFF relay in the start.
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    read_input = Serial.readString();
    read_input.trim();

    input = read_input.substring(read_input.length() - 2, read_input.length());  // Returns first

    // Change mode
    if (input == "BT") {
      bt_state = true;
      Serial.println("Bluetooth mode is ON.");
    }
    else if (input == "SW") {
      bt_state = false;
      fan_state = false;
      bulb_state = false;
      tubelight_state = false;
      Serial.println("Switch mode is ON.");
    }
    // Fan control
    else if (input == "F1" && bt_state) {
      fan_state = true;
      Serial.println("The Fan is ON.");
    }
    else if (input == "F0" && bt_state) {
      fan_state = false;
      Serial.println("The Fan is OFF.");
    }
    // Bulb control
    else if (input == "B1" && bt_state) {
      bulb_state = true;
      Serial.println("The Bulb is ON.");
    }
    else if (input == "B0" && bt_state) {
      bulb_state = false;
      Serial.println("The Bulb is OFF.");
    }
    // Tubelight control
    else if (input == "T1" && bt_state) {
      tubelight_state = true;
      Serial.println("The Tubelight is ON.");
    }
    else if (input == "T0" && bt_state) {
      tubelight_state = false;
      Serial.println("The Tubelight is OFF.");
    }

    // Mode switching and controling device
    if (bt_state) {
      digitalWrite(4, LOW);  // Switch mode to Bluetooth
    }
    else {
      digitalWrite(4, HIGH);
    }

    toggle_device(fan_state, 5);  // Controlling Fan
    toggle_device(bulb_state, 6);  // Controlling Bulb
    toggle_device(tubelight_state, 7);  // Controlling Tubelight
  }
}

void toggle_device(bool condition, int pin)
{
  if (condition) {
    digitalWrite(pin, LOW);
  }
  else {
    digitalWrite(pin, HIGH);
  }
}
