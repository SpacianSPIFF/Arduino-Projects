int r=9,g=10,b=11;
void setup() {
  pinMode(r,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(b,OUTPUT);
}

void loop() {
  setcolour(255,66,0);//In the format of (R,G,B)
}
void setcolour(int red,int green,int blue)
{
  analogWrite(r,red);
  analogWrite(g,green);
  analogWrite(b,blue);
}
//For 1K RESISTOR on each anode of each colour-Orange=(255,6,0);Pink=(255,0,7);White=(255,115,155);Yellow=(255,66,0);Light Blue=(0,255,255);Lavender=(102,0,204);Sea Green=(0,190,100);
