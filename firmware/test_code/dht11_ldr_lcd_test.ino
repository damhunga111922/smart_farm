#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN A3
#define DHTTYPE DHT11
#define LIGHT_PIN A2

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  
  dht.begin();

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("System Start...");
  delay(2000);
  lcd.clear();
}

void loop() {

  float temperature = dht.readTemperature();
  int lightValue = analogRead(LIGHT_PIN);

  // Serial monitor
  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" C  Light: ");
  Serial.println(lightValue);

  // LCD
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C   ");

  lcd.setCursor(0,1);
  lcd.print("Light: ");
  lcd.print(lightValue);
  lcd.print("   ");

  delay(2000);
}