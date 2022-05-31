int noise_val = 0;
int noise_sampling = 100;
bool is_on =  false;

void setup() {
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  for (int i = 0; i < noise_sampling; i++) {
    int noise_reading = analogRead(A0);
    noise_val += noise_reading;
  }
  noise_val /= noise_sampling;

  digitalWrite(9, is_on);
}

void loop() {
  int mic_reading = analogRead(A0);
  mic_reading -= noise_val;
  if (mic_reading < 0) {
    mic_reading = 0;
  }
  Serial.println(mic_reading);
  if (mic_reading > 10) {
    if (is_on) {
      is_on = false;
    }
    else {
      is_on = true;
    }
    digitalWrite(9, is_on);
  }
}
