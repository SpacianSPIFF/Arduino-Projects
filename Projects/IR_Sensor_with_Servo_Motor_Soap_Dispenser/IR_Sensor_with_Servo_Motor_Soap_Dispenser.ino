#include <Servo.h>

Servo servo;
int servoPin = 9;
int irPin = 12;

int reading = 0;

void setup() {
  pinMode(servoPin, OUTPUT);
  pinMode(irPin, INPUT);
  Serial.begin(9600);
  servo.attach(servoPin);
  servo.write(75);
}

void loop() {
  reading = digitalRead(irPin);
  Serial.println(reading);
  if (reading == LOW) {
    servo.write(75);
    delay(200);
    
    servo.write(163);
    delay(200);
    
    servo.write(75);
    delay(200);
  }
} 
