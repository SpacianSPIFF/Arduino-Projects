int Y=0,X=0;
void setup() {
  pinMode(3,INPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  for(int i=6;i<=9;i++)
  {
    pinMode(i,OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  Y=analogRead(A0);
  X=analogRead(A1);
  Serial.print("Y=");
  Serial.println(Y);
  Serial.print("X=");
  Serial.println(X);
  if(X<=1023 and X>=1000 and Y<=1023 and Y>=125) //Top LED
  {
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(6,HIGH);
    Serial.println("The Top LED is ON.");
  }
  if(X<=1000 and X>=50 and Y<=1023 and Y>=1000) //Right LED
  {
    digitalWrite(6,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(7,HIGH);
    Serial.println("The Right LED is ON.");
  }
  if(X<=75 and X>=0 and Y<=1023 and Y>=0) //Bottom LED
  {
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,HIGH);
    Serial.println("The Bottom LED is ON.");
  }
  if(X<=1023 and X>=75 and Y<=125 and Y>=0) //Left LED
  {
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    Serial.println("The Left LED is ON.");
  }
  if(X<=520 and X>=460 and Y<=550 and Y>=485) //All LED OFF
  {
    delay(125);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    Serial.println("All LEDs are OFF.");
  }
  delay(125);
}
