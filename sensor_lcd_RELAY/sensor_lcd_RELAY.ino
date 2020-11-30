#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{  
  lcd.begin(16, 2);
  //start serial connection
  //configure pin2 as an input and enable the internal pull-up resistor
  pinMode(10, INPUT_PULLUP);
  pinMode(9, OUTPUT);
   //lcd.setCursor(0, 0);
   lcd.print("fire detection");
   lcd.setCursor(0, 1);
   lcd.print("System");
   delay(1000);
   lcd.clear();
   
   for(int i=0; i<=15;i++)
   {
   lcd.setCursor(i, 1);
   lcd.print("System");
   delay(200);
   lcd.clear();   
   }
}

void loop() {
  //read the pushbutton value into a variable
  int sensorVal = digitalRead(10);
  //print out the value of the pushbutton
 
  if (sensorVal == LOW)
  { 
    lcd.clear();
    digitalWrite(9, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("fire detected");
    delay(20);
  } 
  else 
  { 
    lcd.clear();
    digitalWrite(9, LOW);
    lcd.setCursor(0, 0);
    lcd.print("fire Not ");
    lcd.setCursor(0, 1);
    lcd.print("detected");
    delay(20);
  }
  
}
