#include <Servo.h>

Servo servo;
int ePin = A0;
int wPin = A1;
int east = 0;
int west = 0;
int diff = 0;
int err = 10;
int pos = 130;


void setup() {
  servo.attach(9);
  Serial.begin(9600); 
}

void loop() {
  east = analogRead(ePin);
  west = analogRead(wPin);

  if (east < 400 && west < 400) {  
    while (pos <=140 && pos >=15) {
      pos ++;
      servo.write(pos);
      delay(100);
    }
  }

  diff = east - west ;
  if (diff > 10) {
    if (pos <= 140) {
      pos ++;
      servo.write(pos);
    }
  } else if (diff < -10) {
    if (pos >= 15) {
      pos --;
      servo.write(pos);
    }
  }
  delay(100);
}
