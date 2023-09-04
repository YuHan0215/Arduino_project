#include <DS1302.h>
DS1302 clock1(5,6,7);//rst 5 dat 6 clk 7
Time t;
int Sec,Min,Hour;
void setup() {
  Serial.begin(9600);
  clock1.writeProtect(false);//可以改
  clock1.halt(false);

  clock1.setDate(20,4,2020);
  clock1.setDOW(MONDAY);
  clock1.setTime(10,54,0);
}

void loop() {
  Serial.print(clock1.getDateStr());Serial.print("\t");
  Serial.print(clock1.getDOWStr());Serial.print("\t");
  Serial.println(clock1.getTimeStr());
  t=clock1.getTime();
  Sec=t.sec;
  Min=t.min;
  Hour=t.hour;
  if (Sec==10 and Min==54 and Hour==10){
    Serial.println("time out");
  }
  delay(1000);

}
