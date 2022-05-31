int pot=0,ledval;
void setup() {
  pinMode(A0,INPUT);
  pinMode(9,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  pot=analogRead(A0);
  ledval=map(pot,0,1023,0,255);
  analogWrite(9,ledval);
  Serial.print("The potentiometer reading=");
  Serial.println(pot);
  Serial.print("The valu of LED=");
  Serial.println(ledval);
}
