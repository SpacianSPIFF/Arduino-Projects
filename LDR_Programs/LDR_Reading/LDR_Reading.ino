// Formula : V0 = V1[R2/(R1+R2)]
// LDR Max Resistance : 19.5K (20K)

int reading = 0;
int resistance = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  reading = analogRead(A0);
  // reading = 1023 - reading; // For LDR being second, and resistor being first.
  Serial.println(reading);
}
