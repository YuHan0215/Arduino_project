int BLed=10; int RLed=11;
int tmp=0;
void setup() {
  pinMode(BLed,OUTPUT);
  pinMode(RLed,OUTPUT);
}

void loop() {
  for (int i=0;i<50;i++){
    analogWrite(BLed,i);
    analogWrite(RLed,50-i);
    delay(30);
  }
  for (int i=50;i>0;i--){
    analogWrite(BLed,i);
    analogWrite(RLed,50-i);
    delay(30);
  }
}
