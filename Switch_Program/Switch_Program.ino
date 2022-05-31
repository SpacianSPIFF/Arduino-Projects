int sw=0;
void setup() {
  pinMode(3,INPUT);
  pinMode(7,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sw=digitalRead(3);
  if(sw==1)
  {
    digitalWrite(7,HIGH);
    Serial.println("HIGH");
  }
  else
  {
    digitalWrite(7,LOW);
    Serial.println("LOW");
  }
}
