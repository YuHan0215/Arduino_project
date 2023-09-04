#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C alice_lcd(0x27,16,2); //16字元  2行
void setup() {
  Serial.begin(9600);
  Serial.println("lcd is ready");
  
  alice_lcd.init();
  alice_lcd.backlight();
  alice_lcd.print("lcd is ready");
}
void loop() {
  /*
  alice_lcd.autoscroll();
  alice_lcd.setCursor(4,1);  //第五格,第二行
  alice_lcd.print("lcd is ready");
*/
  
  alice_lcd.setCursor(0,0);  
  alice_lcd.print("lcd is ready");
  alice_lcd.setCursor(0,1);
  alice_lcd.print("lcd is ready");  
}
