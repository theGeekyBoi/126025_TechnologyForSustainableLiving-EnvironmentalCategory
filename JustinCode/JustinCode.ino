#include <Servo.h>
#include <LiquidCrystal.h>
#define trig1 6
#define echo1 7
long duration1;
int distance1;
#define trig2 8
#define echo2 9
long duration2;
int distance2;
int cap;
int x;
int t;
int f;
Servo myservo;
int pos = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
  lcd.begin(16, 2);
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  myservo.attach(10);
  Serial.begin(9600);
}
void loop()
{
 if(Serial.available() > 0){

 }
  digitalWrite(trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);
  duration2 = pulseIn(echo2, HIGH);
  distance2 = duration2 * 0.034 / 2;
  x = distance2*4;
  cap = x;
  
  lcd.setCursor(0, 0);
  lcd.print("Box Cap. = ");
  lcd.setCursor(12, 0);
  lcd.print(cap);
  lcd.setCursor(15, 0);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Hi I'm Justin!");
  

  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  duration1 = pulseIn(echo1, HIGH);
  distance1 = duration1 * 0.034 / 2;
  t = millis() / 1000;
  
  if(t%4 == 0)
  {
    lcd.clear();
  }
  if(distance1 <= 5)
  {
    ope();
    delay(15);
    
  }
  Serial.println(cap);
  delay(1000);
  
}

void ope()
{
  for (pos = 0; pos <= 90; pos += 2)
  {
    myservo.write(pos);
    delay(15);
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Thanks for");
  lcd.setCursor(0, 1);
  lcd.print("feeding me!  :)");
  delay(7500);
  for (pos = 180; pos >= 0; pos -= 2) 
  {
    myservo.write(pos);
    delay(15);
  }
 
  
}
