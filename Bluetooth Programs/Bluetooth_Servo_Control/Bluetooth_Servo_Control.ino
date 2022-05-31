#include <Servo.h> 

Servo servo;

const int servoPin = 9;
String input;
int val = 0;

void setup() {
  servo.attach(servoPin);
  Serial.begin(9600);
  servo.write(0);
}

void loop() {
  if (Serial.available() > 0) {
    input = Serial.readString();
    input.trim();
    Serial.println(input);
    digit_check(input);
    val = input.toInt();
    if (val > 180 || val < 0) {
      Serial.println("The number should be between 180 and 0.");
      return;
    }
    servo.write(val);
    Serial.println("Servo is at " + String(val) + " Degrees.");
  }
}

void digit_check(String input) {
  for (int i = 0; i < input.length(); i++) {
    if (!isDigit(input[i])) {
      Serial.println("Please enter a Whole Number only.");
      break;
    }
  }
}
