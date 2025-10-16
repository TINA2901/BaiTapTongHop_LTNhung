#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int btn = 7;
int xanh = 10;
int ledDo = 9;
int vang = 8;
int lm35 = A0;
int pre = LOW;
bool doC = true;

void setup() {
  lcd.begin(16,2);
  pinMode(btn,INPUT);
  pinMode(xanh, OUTPUT);
  pinMode(ledDo, OUTPUT);
  pinMode(vang, OUTPUT);

}

void loop() {
  int val = analogRead(lm35);
  float vl = val * 5.0 / 1023.0;
  float tempC = vl * 100.0;
  float tempF = (tempC * 1.8) + 32;
  //
  int cur = digitalRead(btn);
  if(cur == HIGH && pre == LOW){
    doC = !doC;
  }
  //
  if(doC){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(tempC);
    lcd.print(" C");
  }else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(tempF);
    lcd.print(" F");
  }
  //
  if(tempC < 17){
    digitalWrite(vang, LOW);
    digitalWrite(ledDo, LOW);
    digitalWrite(xanh,HIGH);
  }else if (tempC < 31 ){
    digitalWrite(vang, HIGH);
    digitalWrite(ledDo, LOW);
    digitalWrite(xanh,LOW);
  }else{
    digitalWrite(vang, LOW);
    digitalWrite(ledDo, HIGH);
    digitalWrite(xanh,LOW);
  }
  
  //
  pre = cur;
  delay(100);
}
