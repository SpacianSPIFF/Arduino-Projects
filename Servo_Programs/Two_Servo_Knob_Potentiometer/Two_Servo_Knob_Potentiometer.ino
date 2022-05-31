#include <VarSpeedServo.h> 
 
VarSpeedServo myservo1;
VarSpeedServo myservo2;

const int potPin1 = A0;  // analog pin used to connect the potentiometer
const int servoPin1 = 9;  // the digital pin used for the servo
const int potPin2 = A1;
const int servoPin2 = 10;

int val1;  // variable to read the value from the analog pin
int val2;

void setup() {
  myservo1.attach(servoPin1);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(servoPin2);
}

void loop() {
  val1 = analogRead(potPin1);            // reads the value of the potentiometer (value between 0 and 1023)
  val1 = map(val1, 0, 1023, 0, 180);     // scale it to use it with the servo (value from 0 and 180)
  myservo1.write(val1, 127, false);                  // sets the servo position according to the scaled value

  val2= analogRead(potPin2);
  val2 = map(val2, 0, 1023, 0, 180);
  myservo2.write(val2, 127, false);
  
  delay(15);                             // waits a bit before the next value is read and written
}
