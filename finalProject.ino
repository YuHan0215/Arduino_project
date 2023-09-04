#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include <SoftwareSerial.h>
#include <DS1302.h>

#include <IRremote.h>
#include <IRremoteInt.h>

//lcd
LiquidCrystal_I2C lcd(0x27,16,2); //16字元  2行  SDA A4 SCL A5

//clock
DS1302 clock1(5,6,7);//rst 5 dat 6 clk 7
Time t; int Sec;

//bluetooth
int TxD=3; int RxD=4;char c; 
SoftwareSerial BTSerial(TxD,RxD);

//風扇
int inA=10, inB=9;

//IR
int IRpin=8;
IRrecv myIR(IRpin);
decode_results IRresults;

//buz
int buz=11; int dt=200;
int Do=262,Re=294,Mi=330,Fa=349,So=392,La=440,Si=494,So_is=415,C=523,D=587,E=659,Dis=622;

//mode
int mode=0;  //0 off , 1 normal , 2 bluetooth , 3 定時, 4 auto

//condition
int Speed=0;int times=0;


void setup() {
  BTSerial.begin(9600);Serial.begin(9600);
  
  clock1.writeProtect(false);//可以改
  clock1.halt(false);
  clock1.setDate(20,4,2020);
  clock1.setDOW(MONDAY);
  clock1.setTime(10,54,0);

  lcd.init();
  lcd.backlight();
  

  myIR.enableIRIn();

  pinMode(inA,OUTPUT);
  pinMode(inB,OUTPUT);

  pinMode(buz,OUTPUT);
}

void loop() {
  if (myIR.decode(&IRresults)){
    Serial.println(IRresults.value,HEX);
    if(IRresults.value == 0xFFA857){          //+
      mode=1;
    }
    else if (IRresults.value == 0xFFE01F ){    //-
      mode=0;
    }
    else if (IRresults.value == 0xFF30CF){    //1
      mode=2;
    }
    else if (IRresults.value == 0xFF18E7 ){    //2
      mode=3;
    }
    else if (IRresults.value == 0xFF7A85){    //3
      mode=4;
    }
    else if (IRresults.value == 0xFF7A85){    //ˋ
      mode=5;
    }
    else if(IRresults.value == 0xFFE21D  ){          //ch+
      if ( mode==1 ){
        Speed+=60;
        if ( Speed>180 ) Speed=180;
      }
      else if ( mode==3 ){
        times+=1;
        if ( times>30 ) times=30;
      }
    }
    else if (IRresults.value == 0xFFA25D ){    //ch-
      if ( mode==1 ){
        Speed-=60;
        if ( Speed<0 ) Speed=0;
      }
      else if ( mode==3 ){
        times-=1;
        if ( times<0 ) times=0;
      }
    } 
    myIR.resume(); 
  }
//////////
  if ( mode==0 ){
    analogWrite(inA,0);
    analogWrite(inB,0);
    
    lcd.setCursor(0,0);  
    lcd.print("Mode:           ");
    lcd.setCursor(0,1); 
    lcd.print("OFF             ");
    
  }
  else if ( mode==1 ){
    
    analogWrite(inA,Speed);
    analogWrite(inB,0);
    //Serial.print("Speed= ");Serial.println(Speed);

    
    lcd.setCursor(0,0);  
    lcd.print("Mode:   ");
    lcd.print("Speed:  ");
    lcd.setCursor(0,1); 
    lcd.print("Normal  ");
    lcd.print(Speed);
    lcd.print("   ");
    
  }
  else if ( mode==2 ){
    if (BTSerial.available()){
      c=BTSerial.read();
      Serial.println(c);
      if ( c=='A' || c=='a' ){ 
        Speed+=30;
        if ( Speed>180 ) Speed=180;
      }
      else if ( c=='C' || c=='c' ){ 
        Speed-=30;
        if ( Speed<0 ) Speed=0;
      }
    }
    analogWrite(inA,Speed);
    analogWrite(inB,0);
    Serial.print("Speed= ");Serial.println(Speed);
  
    
    lcd.setCursor(0,0);  
    lcd.print("Mode:   ");
    lcd.print("Speed:  ");
    lcd.setCursor(0,1); 
    lcd.print("BLT     ");
    lcd.print(Speed);
    lcd.print("   ");
    
  }
  else if ( mode==3 ){
    //Serial.print("times= ");Serial.println(times);

    
    lcd.setCursor(0,0);  
    lcd.print("Mode:   "); 
    lcd.print("Time:   ");
    lcd.setCursor(0,1); 
    lcd.print("SetTime ");
    lcd.print(times);
    lcd.print("   ");

    analogWrite(inA,0);
    analogWrite(inB,0);
  }
  else if ( mode==4 ){
    t=clock1.getTime();
    Sec=t.sec;
    
    while(times){
      t=clock1.getTime();
      analogWrite(inA,Speed);
      analogWrite(inB,0);
      if (Sec!=t.sec){
        Sec=t.sec;
        times--;
        
        lcd.setCursor(0,0);  
        lcd.print("Mode:   "); 
        lcd.print("Time:   ");
        lcd.setCursor(0,1); 
        lcd.print("SetTime ");
        lcd.print(times);
        lcd.print("   ");
      }
    }
    analogWrite(inA,0);
    analogWrite(inB,0);

  }
  else if ( mode==5 ){
    lcd.setCursor(0,0);  
    lcd.print("Mode:   ");
    lcd.print("        ");
    lcd.setCursor(0,1); 
    lcd.print("Music   ");
    lcd.print("        ");
    analogWrite(inA,100);
    analogWrite(inB,0);
    tone(buz,C,dt);delay(dt);
    tone(buz,D,dt);delay(dt);
    tone(buz,E,dt*2);delay(dt);
    tone(buz,Si,dt);delay(dt);
    tone(buz,C,dt*2);delay(dt);
    tone(buz,E,dt*2);delay(dt);
    tone(buz,Si,dt*2);delay(dt);
    delay(dt*2);
    analogWrite(inA,60);
    analogWrite(inB,0);
    tone(buz,Fa,dt*2);delay(dt);
    tone(buz,La,dt*2);delay(dt);
    tone(buz,So,dt);delay(dt);
    tone(buz,La,dt*2);delay(dt);
    tone(buz,C,dt*2);delay(dt);
    tone(buz,Fa,dt*2);delay(dt);
    delay(dt*2);
    analogWrite(inA,100);
    analogWrite(inB,0);
    tone(buz,Fa,dt);delay(dt);
    tone(buz,Mi,dt);delay(dt);
    tone(buz,Fa,dt*2);delay(dt);
    tone(buz,Mi,dt);delay(dt);
    tone(buz,Fa,dt*2);delay(dt);
    tone(buz,E,dt*2);delay(dt);
    tone(buz,Mi,dt*2);delay(dt);
    analogWrite(inA,60);
    analogWrite(inB,0);
    tone(buz,C,dt);delay(dt);
    tone(buz,C,dt);delay(dt);
    tone(buz,C,dt);delay(dt);
    tone(buz,C,dt*2);delay(dt);
    tone(buz,So_is,dt);delay(dt);
    tone(buz,So_is,dt*2);delay(dt);
    tone(buz,D,dt*2);delay(dt);
    tone(buz,Si,dt*2);delay(dt);
    delay(dt*2);
  }

}
