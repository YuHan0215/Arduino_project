float t=0,distance=0;
float v=0.5*(331+0.6*25)*100/1000000;
int trig=6; int echo=7; int Buz=11;
void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(Buz,OUTPUT);
}

void loop() {
  
  digitalWrite(trig,LOW);delay(1);
  digitalWrite(trig,HIGH);delay(5);
  digitalWrite(trig,LOW);         //送出訊號
  
  t=pulseIn(echo,HIGH);  //接收高電位  
  distance=t*0.0172;  //t*v
  Serial.print(distance);Serial.println(" cm");
  if (distance<2 or distance>400){
    return;
  }
  else if (distance<=10){
    tone(Buz,200,50);delay(150);
  }
  else if (distance>10 and distance<=15){
    tone(Buz,200,150);delay(300);
  }
  else{
    tone(Buz,200,250);delay(450);
  }
  
  //delay(200);
}
