int reading = 0;
int ambient_ir = 0;
int Heart_rate = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
}

//Taking readings and plotting.
void loop() 
{
  for(int i = 0; i < 5; i++)
  {
    reading = reading + analogRead(A0); // Junk IR Light calculation for removal.
  }
  ambient_ir = (reading) / 5;
  delay(50);
  Heart_rate = analogRead(A0) - ambient_ir;
  Serial.println(Heart_rate);
}
