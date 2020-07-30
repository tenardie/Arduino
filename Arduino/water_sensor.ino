#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define An A0
int nem = 0;

LiquidCrystal_I2C lcd(0x3F,16,2);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  nem = analogRead(An);
  home();
  lcd.print("Nem Orani : %");
  lcd.print(nem);
  lcd.setCursor(0,1);
  if(nem > 50){
    lcd.print("Durum: Iyi");
  }
  else if(nem > 30){
    lcd.print("Durum: Normal");
  }
  else if(nem < 31){
    lcd.print("Durum: Kuru");
  }
  else{
    lcd.print("Veri Okunamiyor");  
  }
  delay(2000);
  lcd.clear();
}

void home(){
  lcd.setCursor(0,0);  
}
