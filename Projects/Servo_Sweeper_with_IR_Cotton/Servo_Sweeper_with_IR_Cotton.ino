#include <Servo.h>

Servo servo;

int pos = 0;
int irPin = 12;
int reading = 0;

void setup() {
  pinMode(irPin, INPUT);
  Serial.begin(9600);
  servo.attach(9);
  servo.write(0);
}

void loop() {
  reading = digitalRead(irPin);
  Serial.println(reading);
  
  if (reading == 0) {
    for (pos = 0; pos <= 180; pos += 1) {
      servo.write(pos);
      delay(15);
    }
    for (pos = 180; pos >= 0; pos -= 1) {
      servo.write(pos);
      delay(15);
    }
  }
}
