#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

byte chuAW[] = {   
  B01010,
  B00100,
  B00100,
  B01010,
  B11111,
  B10001,
  B10001,
  B00000
};
byte chuAA[] = {   
  B01110,
  B10001,
  B00100,
  B01010,
  B11111,
  B10001,
  B10001,
  B00000
};
byte chuDD[] = {   
  B01100,
  B01010,
  B01001,
  B11101,
  B01001,
  B01010,
  B01100,
  B00000
};
byte chuEE[] = {   
  B00100,
  B01010,
  B00000,
  B01110,
  B01000,
  B01110,
  B01000,
  B01110
};
byte chuOO[] = {   
  B00100,
  B01010,
  B00000,
  B01110,
  B10001,
  B10001,
  B01110,
  B00000
};
byte chuOW[] = {   
  B00010,
  B00001,
  B01110,
  B10010,
  B10010,
  B10010,
  B01100,
  B00000
};
byte chuUW[] = {   
  B00010,
  B00001,
  B10010,
  B10010,
  B10010,
  B10010,
  B01100,
  B00000
};

void setup() {
  lcd.begin(16,2);

  lcd.createChar(0, chuAW);
  lcd.createChar(1, chuAA);
  lcd.createChar(2, chuDD);
  lcd.createChar(3, chuEE);
  lcd.createChar(4, chuOO);
  lcd.createChar(5, chuOW);
  lcd.createChar(6, chuUW);

  lcd.clear();
  lcd.setCursor(0,0);

  for (int i = 0; i < 7; i++) {
    lcd.write(byte(i)); 
    lcd.print(' ');
  }
}

void loop() {}
