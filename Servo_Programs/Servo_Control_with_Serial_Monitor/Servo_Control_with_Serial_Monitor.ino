#include <VarSpeedServo.h> 
 
VarSpeedServo myservo;

const int servoPin = 9;

int val = 0;

void setup() {
  myservo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    val = int(Serial.read());
    Serial.println(val);
  }
  myservo.write(val);
  delay(15);
}
