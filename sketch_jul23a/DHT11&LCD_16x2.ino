//tenaride
#include <hd44780.h>
#include <TinyDHT.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.init();
  lcd.begin(16,2);
  dht.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Baslatiliyor...");
  delay(1000);
  lcd.clear();
}

void loop() {
  lcd.clear();
  lcd.setCursor(0,0);
  int8_t nem = dht.readHumidity();
  int16_t sicaklik = dht.readTemperature();
  if ( sicaklik == BAD_TEMP || nem == BAD_HUM ) {         
    lcd.print("HATA!");
    lcd.setCursor(0,1);
    lcd.print("Olcum yapilamadi");
  }
  else{
    lcd.print("Sicaklik :");
    lcd.setCursor(10,0);
    lcd.print(sicaklik);
    lcd.setCursor(0,1);
    lcd.print("Nem :");
    lcd.setCursor(6,1);
    lcd.print(nem);
    lcd.setCursor(9,1);
    lcd.print("%\t");
    }
  delay(2000);
}
