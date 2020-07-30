#include <SoftwareSerial.h> 

SoftwareSerial bt_hc04(0, 1);

#define ileri_pin 12
#define geri_pin 11

void setup() {
  Serial.begin(9600);
  bt_hc04.begin(9600);
  pinMode(ileri_pin, OUTPUT);
  pinMode(geri_pin_pin, OUTPUT);
}

void loop() {
  if (bt_hc04.available()){
    char data = bt_hc04.read();
    Serial.println(data);
    if (data == '1'){
      digitalWrite(ileri_pin, 1);
      digitalWrite(geri_pin, 0);
      delay(3000);
      digitalWrite(ileri_pin, 0);
      digitalWrite(geri_pin, 1);
      delay(3000);
      digitalWrite(ileri_pin, 0);
      digitalWrite(geri_pin_pin, 0);
    }
  }
}
