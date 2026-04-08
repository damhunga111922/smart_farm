#include <DHT.h>

#define DHTPIN A3        // Chân DATA nối với D2
#define DHTTYPE DHT11   // Khai báo loại cảm biến

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Khoi dong DHT11...");
  dht.begin();
}

void loop() {
  delay(2000);  // DHT11 đọc tối đa 1 lần / 1-2 giây

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // Celsius

  // Kiểm tra lỗi đọc
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Loi doc cam bien DHT11!");
    return;
  }

  Serial.print("Do am: ");
  Serial.print(humidity);
  Serial.print(" %  |  Nhiet do: ");
  Serial.print(temperature);
  Serial.println(" *C");
}