#include <VarSpeedServo.h>

VarSpeedServo servo1;
VarSpeedServo servo2;

const int servoPin1 = 9;
const int servoPin2 = 10;

void setup() { 
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo1.write(40 ,255, false);
  servo2.write(40, 255, true);
}

void loop() {
  servo1.write(100, 127, false);
  servo2.write(100, 127, true);
  
  servo1.write(40, 30, false);
  servo2.write(40, 30, true);
}
