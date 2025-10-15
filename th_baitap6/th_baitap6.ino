#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int btnBatTat = 10;
int btnTrai = 9;
int btnPhai = 8;

int preBatTat = LOW;
int preTrai = LOW;
int prePhai = LOW;

bool trangThai = true;
int x = 0;
int y = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(btnBatTat, INPUT);
  pinMode(btnTrai, INPUT);
  pinMode(btnPhai, INPUT);

  lcd.setCursor(x, y);
  lcd.print("HELLO");
}

void loop() {
  int curBatTat = digitalRead(btnBatTat);
  int curTrai = digitalRead(btnTrai);
  int curPhai = digitalRead(btnPhai);

  
  if (curBatTat == HIGH && preBatTat == LOW) {
    trangThai = !trangThai;
    delay(200); 
  }

  if (trangThai) {
    lcd.display();
    
    if (curTrai == HIGH && preTrai == LOW) {
      x -= 2;
      if (x < 0) {
        x = 15;
        if(y==0){
          y=1;
        }else y=0;
      }
      lcd.clear();
      lcd.setCursor(x, y);
      lcd.print("HELLO");
      delay(200);
    }

    if (curPhai == HIGH && prePhai == LOW) {
      x += 2;
      if (x > 15) {
        x = 0;
        if(y==0) y=1;
        else y=0;
      }
      lcd.clear();
      lcd.setCursor(x, y);
      lcd.print("HELLO");
      delay(200);
    }
  } else {
    lcd.noDisplay();
  }

  preBatTat = curBatTat;
  preTrai = curTrai;
  prePhai = curPhai;
}
