#include <DHT.h>

#define DHTPIN A3
#define DHTTYPE DHT11
#define LIGHT_PIN A2

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Khoi dong he thong...");
  dht.begin();
}

void loop() {
  delay(2000);  // DHT11 cần delay >= 1-2s

  // Đọc DHT11
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Đọc cảm biến ánh sáng
  int lightValue = analogRead(LIGHT_PIN);

  // Kiểm tra lỗi DHT
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Loi doc DHT11!");
  } else {
    Serial.print("Nhiet do: ");
    Serial.print(temperature);
    Serial.print(" *C  |  Do am: ");
    Serial.print(humidity);
    Serial.println(" %");
  }

  Serial.print("Anh sang (ADC): ");
  Serial.println(lightValue);

  Serial.println("----------------------");
}