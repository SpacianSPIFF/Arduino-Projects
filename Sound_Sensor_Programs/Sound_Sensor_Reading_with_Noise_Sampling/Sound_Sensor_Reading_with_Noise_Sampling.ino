int noise_val = 0;
int noise_sampling = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  Serial.begin(9600);
  for (int i = 0; i < noise_sampling; i++) {
    int noise_reading = analogRead(A0);
    noise_val += noise_reading;
  }
  noise_val /= noise_sampling;
}

void loop() {
  // put your main code here, to run repeatedly:
  int mic_reading = analogRead(A0);
  mic_reading -= noise_val;
  if (mic_reading < 0) {
    mic_reading = 0;
  }
  if (mic_reading > 10) {
    Serial.println(mic_reading);
  }
}
