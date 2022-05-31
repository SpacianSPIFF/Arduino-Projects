void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int mic_reading = analogRead(A0);
  if (mic_reading < 0) {
    mic_reading = 0;
  }
  if (mic_reading > 10) {
    Serial.println(mic_reading);
  }
}
