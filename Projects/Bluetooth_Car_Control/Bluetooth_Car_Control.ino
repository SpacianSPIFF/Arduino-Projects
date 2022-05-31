String input;
int forward = 0, right = 0, backward = 0, left = 0;

void setup() {
  // put your setup code here, to run once:
  for (int i = 4; i <= 7; i++) {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    input = Serial.readString();
    input.trim();
    forward = String(input[0]).toInt();
    backward = String(input[1]).toInt();
    right = String(input[2]).toInt();
    left = String(input[3]).toInt();
    Serial.println(input);
    if(!(input == "0000")) {
//      if (forward == 1 && left == 1) {
//        digitalWrite(4, 1);
//        digitalWrite(5, 0);
//        digitalWrite(6, 1);
//        digitalWrite(7, 0);
//        Serial.println("Forward Left");
//      }
//      else if (forward == 1 && right == 1) {
//        digitalWrite(4, 0);
//        digitalWrite(5, 0);
//        digitalWrite(6, 0);
//        digitalWrite(7, 0);
//        Serial.println("Forward Right");
//      }
//      else if (backward == 1 && right == 1) {
//        digitalWrite(4, 0);
//        digitalWrite(5, 0);
//        digitalWrite(6, 0);
//        digitalWrite(7, 0);
//        Serial.println("Backword Right");
//      }
//      else if (backward == 1 && left == 1) {
//        digitalWrite(4, 0);
//        digitalWrite(5, 1);
//        digitalWrite(6, 1);
//        digitalWrite(7, 0);
//        Serial.println("Backward Left");
//      }
      if (forward == 1) {
        CarControl(1, 0, 1, 0);
//        digitalWrite(4, 1);
//        digitalWrite(5, 0);
//        digitalWrite(6, 1);
//        digitalWrite(7, 0);
        Serial.println("Forward");
      }
      else if (backward == 1) {
        CarControl(0, 1, 0, 1);
//        digitalWrite(4, 0);
//        digitalWrite(5, 1);
//        digitalWrite(6, 0);
//        digitalWrite(7, 1);
        Serial.println("Backward");
      }
      else if (left == 1) {
        CarControl(1, 0, 0, 1);
//        digitalWrite(4, 1);
//        digitalWrite(5, 0);
//        digitalWrite(6, 0);
//        digitalWrite(7, 1);
        Serial.println("Left");
      }
      else if (right == 1) {
        CarControl(0, 1, 1, 0);
//        digitalWrite(4, 0);
//        digitalWrite(5, 1);
//        digitalWrite(6, 1);
//        digitalWrite(7, 0);
        Serial.println("Right");
      }
    }
    else {
      CarControl(0, 0, 0, 0);
//      digitalWrite(4, 0);
//      digitalWrite(5, 0);
//      digitalWrite(6, 0);
//      digitalWrite(7, 0);
    }
  }
}

void CarControl(int a, int b, int c, int d) {
  digitalWrite(4, a);
  digitalWrite(5, b);
  digitalWrite(6, c);
  digitalWrite(7, d);
}
