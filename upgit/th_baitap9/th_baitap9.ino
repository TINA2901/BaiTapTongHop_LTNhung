#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

int btnC = 6;
int btnF = 7;
int lm35 = A0;
int preC = LOW;
int preF = LOW;
bool doC = true;

void setup() {
  lcd.begin(16,2);
  pinMode(btnC, INPUT);
  pinMode(btnF, INPUT);
}

void loop() {
  int reading = analogRead(lm35);
  float voltage = reading * 5.0 / 1023.0;
  float tempC = voltage * 100.0;
  float tempF = (tempC * 1.8) + 32;
  
  int curC = digitalRead(btnC);
  int curF = digitalRead(btnF);

  if(preC == LOW && curC == HIGH){
    doC = true;
  }
  if(preF == LOW && curF == HIGH){
    doC = false;
  }

  if(doC == true){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(tempC);
    lcd.print(" C");
  }if (doC == false){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(tempF);
    lcd.print(" F");
  }
  
  preC = curC;
  preF = curF;
  delay(200);
}
