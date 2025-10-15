

int led[] = {0,1,2,3,4,5,6,7,8,9};

void setup() {
  for (int i = 0; i<10; i++){
    pinMode(led[i], OUTPUT);
  }
}

void loop() {
  for (int i=0; i<10; i++){
    int rand = random(1,10);
    if (rand % 2 == 0){
      digitalWrite(led[i],HIGH);
    }else{
      digitalWrite(led[i],LOW);
    }
  }
}
