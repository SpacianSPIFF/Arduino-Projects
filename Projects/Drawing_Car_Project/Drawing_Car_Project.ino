char z;
void setup() {
  for (int i = 4; i <= 7; i++)
  {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
  Serial.println("To draw a square, please press s.");
  Serial.println("To draw a hexagon, please press h.");
  Serial.println("To draw a circle, please press c.");
  Serial.println("To draw a triangle, please press t.");
}

void loop() {
  if (Serial.available() > 0)
  {
    z = Serial.read();
    Serial.println(z);
    if (z == 's')
    {
      square();
    }
    if (z == 'h')
    {hexagon();
    }
    if (z == 'c')
    {
      circle();
    }
    if (z == 't')
    {
      triangle();
    }
    Serial.println("");
    Serial.println("To draw a square, please press s.");
    Serial.println("To draw a hexagon, please press h.");
    Serial.println("To draw a circle, please press c.");
    Serial.println("To draw a triangle, please press t.");
  }
}

void square()
{
  Serial.println("The car has started to draw a square.");
  digitalWrite(4, 1);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  delay(1500);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  delay(500);
  digitalWrite(4, 1);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 1);
  delay(1500);
  digitalWrite(4, 1);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  delay(1500);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  delay(500);
  digitalWrite(4, 1);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  delay(1500);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  delay(500);
  digitalWrite(4, 1);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 1);
  delay(1500);
  digitalWrite(4, 1);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  delay(1500);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  delay(500);
  Serial.println("The car has finished drawing a square.");
}

void hexagon()
{

}

void circle()
{

}

void triangle()
{

}
