int pot=0;
void setup() {
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop() {
  pot=analogRead(A0);
  Serial.print("The potentiometer reading=");
  Serial.println(pot);
}
