int btnTang = 12;
int btnGiam = 11;
int led = 3;
unsigned long tgTruoc = 0;
long tgDelay = 200;
int delayMax = 5000;
int delayMin = 0;
int preTang = LOW;
int preGiam = LOW;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(btnTang, INPUT);
  pinMode(btnGiam, INPUT);
}

void loop() {
  unsigned long tgHienTai = millis();
  int curTang = digitalRead(btnTang);
  int curGiam = digitalRead(btnGiam);
  if(curTang == HIGH && preTang == LOW){
    tgDelay -=  100;
    if(tgDelay <= delayMin) tgDelay = delayMin;
  }

  if(curGiam == HIGH && preGiam == LOW){
    tgDelay += 100;
    if (tgDelay >= delayMax) tgDelay = delayMax;
  }
  preTang = curTang;
  preGiam = curGiam;
   if(tgHienTai - tgTruoc <= tgDelay){
    digitalWrite(led, HIGH);
   }else if(tgHienTai - tgTruoc <= tgDelay * 2){
    digitalWrite(led, LOW);
   }else{
    tgTruoc = tgHienTai;
   }
   
}
