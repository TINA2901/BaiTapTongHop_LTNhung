#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int btn = 10;
int led = 9;
int pre = LOW;
bool trangThai = false;

void setup() {
  lcd.begin(16,2);
  pinMode(led, OUTPUT);
  pinMode(btn, INPUT);
  digitalWrite(led, HIGH);
  lcd.clear();
}

void loop() {
  int cur = digitalRead(btn);
  if (pre == HIGH && cur == LOW){
    trangThai = !trangThai;
    if (trangThai){
      lcd.clear();
      lcd.print("HELLO");
      digitalWrite(led, LOW);
    }else{
      lcd.clear();
      digitalWrite(led, HIGH);      
    }
  }
  pre = cur;
}
