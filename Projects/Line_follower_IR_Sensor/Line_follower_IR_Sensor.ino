int ir1;
int ir2;

void setup() {
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  for (int i = 2; i <= 8; i+=2){
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // 1 is Black
  // 0 is White
  
  ir1 = 1 - digitalRead(9);
  ir2 = 1 - digitalRead(10);
  if (ir1 == 1 && ir2 == 1) {
    CarControl(1, 0, 1, 0); // Go forward
    Serial.println("Forward");
  }
  if (ir1 == 1 && ir2 == 0) { // Turn left
    CarControl(0, 0, 1, 0);
    Serial.println("Turn Left");
  }
  if (ir1 == 0 && ir2 == 1) { // Turn right
    CarControl(1, 0, 0, 0);
    Serial.println("Turn Right");
    delay(250); // Added due to right motor being a bit faster than the left. Comment if motors have equal speeds
  } 
  if (ir1 == 0 && ir2 == 0) { // Black square for stop
    CarControl(0, 0, 0, 0);
    Serial.println("Stop");
  }
}

void CarControl(int a, int b, int c, int d) {
  digitalWrite(2, a);
  digitalWrite(4, b);
  digitalWrite(6, c);
  digitalWrite(8, d);
}
