const int trigpin=2,echopin=3;
int duration=0;
float CF=1,distance=0;
void setup() {
  pinMode(trigpin,OUTPUT); //trig O/P
  pinMode(echopin,INPUT); //echo I/P
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  for(int i=9;i<=11;i++)
  {
    pinMode(i,OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  digitalWrite(2,LOW);
  delayMicroseconds(2);
  digitalWrite(2,HIGH);
  delayMicroseconds(10);
  digitalWrite(2,LOW);
  duration=pulseIn(3,HIGH);
  distance=(0.034*duration)/2;
  distance=(distance*CF);
  Serial.print("Distance=");
  Serial.print(distance);
  Serial.println("cm");
  LEDAV((distance*100)); //LED Analog Value-Function
  delay(250);
}

void LEDAV(int AV)
{
  float dist=AV/100;
  AV=map(AV,0,400,0,25500);
  AV=AV/100;
  Serial.print("AV=");
  Serial.println(AV);
  DistIndiLED(dist,AV);
}

void DistIndiLED(float dist,int AW)
{
   if(dist>=0 and dist<=4)
   {
    analogWrite(5,AW);
    digitalWrite(6,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
   }
   else if(dist>4 and dist<=8)
   {
    digitalWrite(5,HIGH);
    analogWrite(6,AW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
   }
   else if(dist>8 and dist<=12)
   {
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    analogWrite(9,AW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
   }
   else if(dist>12 and dist<=16)
   {
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(9,HIGH);
    analogWrite(10,AW);
    digitalWrite(11,LOW);
   }
   else if(dist>16 and dist<=20)
   {
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    analogWrite(11,AW);
   }
   else
   {
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
   }
}
