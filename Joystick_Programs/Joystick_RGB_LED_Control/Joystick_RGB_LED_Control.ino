int r=9,g=10,b=11,X=0,Y=0,rval=0,gval=0,bval=0;
void setup() {
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(3,INPUT);
  pinMode(r,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(b,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Y=analogRead(A0);
  X=analogRead(A1);
  rval=map(X,0,1023,0,255);
  gval=map(Y,0,1023,0,115);
  bval=digitalRead(3);
  analogWrite(r,rval);
  analogWrite(g,gval);
  if(bval==1)
  {
    digitalWrite(b,0);
  }
  else
  {
    digitalWrite(b,1);
  }
  Serial.print("X=");
  Serial.println(X);
  Serial.print("Y=");
  Serial.println(Y);
  Serial.print("rval=");
  Serial.println(rval);
  Serial.print("gval=");
  Serial.println(gval);
  Serial.print("bval=");
  Serial.println(bval);
}
