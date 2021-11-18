int order[] = {6,3,4,5,8,7,11};
int score = -1;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT_PULLUP);
  for (int i=0; i<8; i++){
    pinMode(order[i],OUTPUT);

  }
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), incrementScore, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(score < 0){
    zeroCircle();
  } else {
    setDisplay(score);
  }

  Serial.println(score);
 
}

void zeroCircle() {
  
  digitalWrite(order[0], HIGH);
  digitalWrite(order[4],LOW);
  delay(100);
  digitalWrite(order[1], HIGH);
  digitalWrite(order[5], LOW);
  delay(100);
  digitalWrite(order[2], HIGH);
  digitalWrite(order[0], LOW);
  delay(100);
  digitalWrite(order[3],HIGH);
  digitalWrite(order[1],LOW);
  delay(100);
  digitalWrite(order[4], HIGH);
  digitalWrite(order[2], LOW);
  delay(100);
  digitalWrite(order[5],HIGH);
  digitalWrite(order[3],LOW);
  delay(100);
  

}

void setDisplay(int val) {

  int zeroDisp[] = {0,1,2,3,4,5};
  int oneDisp[] = {3,4};
  int twoDisp[] = {2,3,0,5,6};
  int threeDisp[] = {2,3,4,5,6};

  for(int i = 0; i<6; i++) {

    digitalWrite(order[i], LOW);
    
  }

  if (val%10 == 0) {
  
    for (int i = 0; i< sizeof(zeroDisp); i++) {
      digitalWrite(order[zeroDisp[i]], HIGH);
    }
  
  }
  if (val%10 == 1) {
  
    for (int i = 0; i<sizeof(oneDisp); i++) {
      digitalWrite(order[oneDisp[i]], HIGH);
    }
  
  }
  if (val&10 == 2) {
  
    for (int i = 0; i< sizeof(twoDisp); i++) {
      digitalWrite(order[twoDisp[i]], HIGH);
    }
  
  }
  if (val%10 == 3) {
  
    for (int i = 0; i< sizeof(threeDisp); i++) {
      digitalWrite(order[threeDisp[i]], HIGH);
    }
  
  }
  if (val%10 == 4) {
  
    for (int i = 0; i< sizeof(zeroDisp); i++) {
      digitalWrite(order[zeroDisp[i]], HIGH);
    }
  
  }
  if (val%10 == 5) {
  
    for (int i = 0; i< sizeof(zeroDisp); i++) {
      digitalWrite(order[zeroDisp[i]], HIGH);
    }
  
  }
  if (val%10 == 6) {
  
    for (int i = 6; i< sizeof(zeroDisp); i++) {
      digitalWrite(order[zeroDisp[i]], HIGH);
    }
  
  }
}

void incrementScore() {

  score += 1;
  
}
