/*
 * Here is the code for Arduino-based Automated Plant Irrigation System Using arduino Uno
 */

int moistureSensor = 0;
int motor = 2;
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,6,5,4,3);
void setup() {
Serial.begin(9600);
lcd.begin(16,2);
pinMode(motor,OUTPUT);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("    WEL-COME ");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PLANT IRRIGATION");
  lcd.setCursor(0,1);
  lcd.print("     SYSTEM");
  delay(3000);
  lcd.clear();
  int SensorValue = analogRead(moistureSensor);
  if(SensorValue >=400)
{
lcd.setCursor(0,0);
lcd.print("STATUS ....");   
lcd.setCursor(0,1);
lcd.print("        DRY SOIL");
delay(5000);
lcd.clear();
} 
else
{ 
 lcd.setCursor(0,0);
lcd.print("STATUS ....");
lcd.setCursor(0,1);
lcd.print("      HUMID SOIL");
delay(5000);
lcd.clear(); 
}
 }
void loop(){

  int SensorValue = analogRead(moistureSensor);
  lcd.setCursor(0,0);
  lcd.print("SENSOR VAL =");
  lcd.println(SensorValue);

if(SensorValue >=400)
{
   
digitalWrite(motor,HIGH);
lcd.setCursor(0,1);
lcd.print("   *WATERING* ");
} 
else
{ 
digitalWrite(motor,LOW);
lcd.setCursor(0,1);
lcd.print(" *NOT WATERING*"); 
}
 }
