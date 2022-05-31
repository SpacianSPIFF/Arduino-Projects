float CF=1;
int duration=0,distance=0;
void setup() {
  pinMode(5,OUTPUT); //trig
  pinMode(6,INPUT); //echo
  Serial.begin(9600);
}

void loop() {
  digitalWrite(5,LOW);
  delayMicroseconds(2);
  digitalWrite(5,HIGH);
  delayMicroseconds(10);
  digitalWrite(5,LOW);
  duration=pulseIn(6,HIGH);
  distance=(0.034*duration)/2;
  distance=distance*CF;
  Serial.print("Distance=");
  Serial.print(distance);
  Serial.println("cm");
  if(distance<=5) //Proximity Sensor
  {
    Serial.println("An obstacle has been detected at a very close range.");
  }
  else if(distance<=10) //Obstacle Detector
  {
    Serial.println("An obstacle has been detected.");
  }
  delay(500);
}
