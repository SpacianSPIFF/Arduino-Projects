int i=0;
int j=0;
void setup() {
  pinMode(9,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for(int i=0;i<255;i++)
  {
    analogWrite(9,i);
    Serial.print("i=");
    Serial.println(i);
    delay(25);
  }
  delay(50);
  for(int j=255;j>0;j--)
  {
    analogWrite(9,j);
    Serial.print("j=");
    Serial.println(j);
    delay(25);
  }
  delay(50);
}
