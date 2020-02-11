#include <LiquidCrystal.h>

const int rs = 1, en = 2, d4 = A0, d5 = A1, d6 = A2, d7 = A3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//const int rs = 1, en = 2, d4 = 3, d5 = 4, d6 = 5, d7 = 6;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() 
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.write("Enter The Number-");
}

void loop() 
{
   
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(5, 1);
  // print the number of seconds since reset:
  //lcd.print(millis() / 1000);
  
}
