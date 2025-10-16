#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

// ====== TẠO KÝ TỰ ĐẶC BIỆT ======
byte chuEE[] = { // Ê
  B00100,
  B01010,
  B00000,
  B01110,
  B01000,
  B01110,
  B01000,
  B01110
};
byte chuEF[] = { // È
  B01000,
  B00100,
  B00000,
  B01110,
  B01000,
  B01110,
  B01000,
  B01110
};
byte chuES[] = { // É
  B00010,
  B00100,
  B00000,
  B01110,
  B01000,
  B01110,
  B01000,
  B01110
};
byte chuOO[] = { // Ô
  B00100,
  B01010,
  B00000,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110
};
byte chuOS[] = { // Ó
  B00010,
  B00100,
  B00000,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110
};
byte chuOF[] = { // Ò
  B01000,
  B00100,
  B00000,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110
};

// ====== KHAI BÁO NÚT NHẤN ======
int btnE = 9;
int btnO = 8;
int btnF = 7;
int btnS = 6;

int preE = LOW, preO = LOW, preF = LOW, preS = LOW;

// Tọa độ LCD
int x = 0, y = 0;

// Biến nhớ ký tự trước (0 = không có, 1 = E, 2 = O)
int tam = 0;

void setup() {
  lcd.begin(16,2);
  pinMode(btnE, INPUT);
  pinMode(btnO, INPUT);
  pinMode(btnS, INPUT);
  pinMode(btnF, INPUT);

  // Tạo các ký tự đặc biệt
  lcd.createChar(0, chuEE);
  lcd.createChar(1, chuES);
  lcd.createChar(2, chuEF);
  lcd.createChar(3, chuOO);
  lcd.createChar(4, chuOS);
  lcd.createChar(5, chuOF);

  lcd.clear();
}

void loop() {
  int curE = digitalRead(btnE);
  int curO = digitalRead(btnO);
  int curF = digitalRead(btnF);
  int curS = digitalRead(btnS);

  // Khi nhấn E
  if (curE == HIGH && preE == LOW) {
    if (tam == 1) { // E + E -> Ê
      lcd.write(byte(0));
      tam = 0;
      x++;
    } else{
      lcd.print("E");
      tam = 1;
    }
    
  }

  // Khi nhấn O
  if (curO == HIGH && preO == LOW) {
    if (tam == 2) { // O + O -> Ô
      lcd.write(byte(3));
      tam = 0;
      x++;
    } else{
      lcd.print("O");
      tam = 2;
    }
   
  }

  // Khi nhấn S
  if (curS == HIGH && preS == LOW) {
    if (tam == 1) { // E + S -> É
      lcd.write(byte(1));
      tam = 0;
      x++;
    } else if (tam == 2) { // O + S -> Ó
      lcd.write(byte(4));
      tam = 0;
      x++;
    } else {
      lcd.print("S");
      x++;
    }
    
  }

  // Khi nhấn F
  if (curF == HIGH && preF == LOW) {
    if (tam == 1) { // E + F -> È
      lcd.write(byte(2));
      tam = 0;
      x++;
    } else if (tam == 2) { // O + F -> Ò
      lcd.write(byte(5));
      tam = 0;
      x++;
    } else {
      lcd.print("F");
      x++;
    }
    
  }

  // Xuống dòng khi đầy hàng
  if (x > 15) {
    x = 0;
    y = 1 - y; // đổi dòng
    lcd.setCursor(x, y);
  }

  lcd.setCursor(x, y);

  // Cập nhật trạng thái trước
  preE = curE;
  preO = curO;
  preF = curF;
  preS = curS;
}
