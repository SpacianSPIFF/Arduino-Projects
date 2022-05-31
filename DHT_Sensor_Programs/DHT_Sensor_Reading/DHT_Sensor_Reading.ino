#include "DHT.h"

// define pin and type of sensor
#define DHTPIN 4
#define DHTTYPE DHT11

// create sensor object
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT Sensor Reading.");
  dht.begin();
}

void loop() {
  // get temperature and humidity readings
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // check if humidity and temperature  if its not nan 
  if (isnan(temperature) || isnan(humidity)){
      Serial.println("Failed to read from DHT sensor.");
    }
  else {
      Serial.println("Humidity: " + String(humidity));
      Serial.println("Temperature: " + String(temperature));
    }
  delay(1000);
}
