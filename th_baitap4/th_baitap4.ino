int ledDo =5;
int ledVang = 4;
int btn = 8;
int preBtn = LOW;
int dem = 0;
void setup() {
  pinMode(ledDo, OUTPUT);
  pinMode(ledVang, OUTPUT);
  pinMode(btn, INPUT);
}

void loop() {
  int curBtn = digitalRead(btn);
  if (curBtn == HIGH && preBtn == LOW){
    dem++;
  }
  preBtn = curBtn;
  switch(dem){
    case 1:
      digitalWrite(ledDo, HIGH);
      digitalWrite(ledVang, HIGH);
    break;
    case 2:
      digitalWrite(ledDo, LOW);
      digitalWrite(ledVang, LOW);
    break;
    case 3:
      digitalWrite(ledVang, HIGH);
    break;
    case 4:
      digitalWrite(ledDo, HIGH);
      digitalWrite(ledVang, LOW);
      dem=0;
    break;
  }
}
