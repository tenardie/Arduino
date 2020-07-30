#include <Servo.h>
#include <HCSR04.h>

Servo myservo;
UltraSonicDistanceSensor distanceSensor(2, 3);

#define duz 20
#define acik 0
#define kapali 40

int mes;
int son = 1;

void setup() {
  Serial.begin(9600);
  myservo.attach(8);
}

void loop() {
  delay(50);
  mes = (distanceSensor.measureDistanceCm());
  if(mes <= 30){
    if(son == 0){
     ac();
    }
    if(son == 1){
      kapa();  
    }
    switch (son){
    case 1:
    son = 0;
    break;
    case 0:
    son = 1;
    break;  
    }
   delay(1000);
  }
}

void ac(){
  myservo.write(acik);
  delay(1000);
  myservo.write(duz);
}

void kapa(){
  myservo.write(kapali);
  delay(1000);
  myservo.write(duz);
}
