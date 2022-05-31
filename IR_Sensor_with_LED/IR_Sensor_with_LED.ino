int sampling = 100;
int ambient_ir = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(12,OUTPUT);
  for (int i = 0; i < sampling; i++) {
    int reading = analogRead(A0);
    ambient_ir += reading;
    Serial.print("Reading: ");
    Serial.println(ambient_ir);
  }
  ambient_ir /= sampling;
  delay(2000);
  Serial.print("Ambient IR: ");
  Serial.println(ambient_ir);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(A0);
  reading -= ambient_ir;
  Serial.println(reading);
  delay(100);
}
