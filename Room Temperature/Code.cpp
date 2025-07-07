#include "DHT.h"

// DHT Sensor Settings
#define DHTPIN 4          // GPIO4 is connected to the data pin
#define DHTTYPE DHT22     // DHT22 (use DHT11 if that's your sensor)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println("DHT22 Room Temperature Monitor");
  dht.begin();
}

void loop() {
  delay(2000);  // Wait between readings

  float temperature = dht.readTemperature();    // Celsius
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("❌ Failed to read from DHT sensor!");
    return;
  }

  Serial.print("🌡 Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C    💧 Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
}
