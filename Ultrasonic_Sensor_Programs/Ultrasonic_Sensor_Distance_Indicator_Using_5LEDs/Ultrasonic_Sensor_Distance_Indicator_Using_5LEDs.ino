float CF=1;
int duration=0,distance=0;
void setup() {
  pinMode(2,OUTPUT); //trig O/P
  pinMode(3,INPUT); //echo I/P
  for(int i=4;i<=8;i++)
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
  DistIndiLED(distance);
  delay(500);
}

void DistIndiLED(int dist)
{
  if(dist<=3)
  {
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
  }
  else if(dist<=5)
  {
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
  }
  else if(dist<=8)
  {
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
  }
  else if(dist<=11)
  {
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
  }
  else if(dist<=14)
  {
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
  }
  else
  {
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    Serial.println("The object is out of range.");
  }
}
