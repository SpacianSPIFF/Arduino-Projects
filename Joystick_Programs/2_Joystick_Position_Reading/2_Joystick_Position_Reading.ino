int X1=0, Y1=0, K1=0;
int X2=0, Y2=0, K2=0;

void setup() {
  // Joystick 1
  pinMode(3,INPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  
  // Joystick 2
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(4, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // Joystick 1
  Y1=analogRead(A0);
  X1=analogRead(A1);
  K1=digitalRead(3);
  Serial.print("X1=");
  Serial.println(X1);
  Serial.print("Y1=");
  Serial.println(Y1);
  Serial.print("K1=");
  Serial.println(K1);
  
  // Joystick 2
  Y2=analogRead(A2);
  X2=analogRead(A3);
  K2=digitalRead(4);
  Serial.print("X2=");
  Serial.println(X2);
  Serial.print("Y2=");
  Serial.println(Y2);
  Serial.print("K2=");
  Serial.println(K2);

  delay(300);
}
