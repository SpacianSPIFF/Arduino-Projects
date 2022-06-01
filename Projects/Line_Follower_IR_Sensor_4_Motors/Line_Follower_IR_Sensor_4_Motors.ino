int ir_left;
int ir_right;

void setup() {
  // IR Sensor
  pinMode(2, INPUT);
  pinMode(3, INPUT);

  // Motors Pins: [4, 5, 6, 7, 10, 11, 12, 13]
  for (int i = 4; i <= 7; i++) {
    pinMode(i, OUTPUT);
  }
  for (int i = 10; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }

  Serial.begin(9600);
}

void loop() {
  // 1 is White
  // 0 is Black
  ir_left = 1 - digitalRead(2);
  ir_right = 1 - digitalRead(3);

  // CarControl(4, 5, 12, 13, 6, 7, 10, 11);
  if (ir_left == 1 && ir_right == 1) {
    CarControl(0, 1, 1, 0, 0, 1, 1, 0); // Go forward
    Serial.println("Forward");
  }
  if (ir_left == 1 && ir_right == 0) { // Turn left
    CarControl(0, 0, 0, 0, 0, 1, 1, 0);
    Serial.println("Turn Left");
  }
  if (ir_left == 0 && ir_right == 1) { // Turn right
    CarControl(0, 1, 1, 0, 0, 0, 0, 0);
    Serial.println("Turn Right");
  }
  if (ir_left == 0 && ir_right == 0) { // Black square for stop
    CarControl(0, 0, 0, 0, 0, 0, 0, 0);
    Serial.println("Stop");
  }
}

void CarControl(int a, int b, int c, int d, int w, int x, int y, int z) {
  // Left Half
  digitalWrite(4, a);
  digitalWrite(5, b);
  digitalWrite(12, c);
  digitalWrite(13, d);

  // Right Half
  digitalWrite(6, w);
  digitalWrite(7, x);
  digitalWrite(10, y);
  digitalWrite(11, z);
}
