void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  DEMUX(0, 0);
}

void DEMUX(int a, int b)
{
  digitalWrite(3, a);
  digitalWrite(4, b);
}

// A B |Y0 Y1 Y2 Y3
// 0 0 | 0  1  1  1
// 0 1 | 1  1  0  1
// 1 0 | 1  0  1  1
// 1 1 | 1  1  1  0
