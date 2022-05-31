#include <VarSpeedServo.h>

VarSpeedServo servo;  // create servo object to control a servo
                      // a maximum of eight servo objects can be created

const int servoPin = 9; // the digital pin used for the servo

void setup() {
  servo.attach(servoPin);  // attaches the servo on pin 9 to the servo object
  servo.write(0, 255, true); // set the intial position of the servo, as fast as possible, wait until done
}

void loop() {
  servo.write(180, 255, true);        // move the servo to 180, max speed, wait until done
                                      // write(degrees 0-180, speed 1-255, wait to complete true-false)
  servo.write(0, 30, true);           // move the servo to 180, slow speed, wait until done
}
