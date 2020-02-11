#include <Keypad.h>
#include <LiquidCrystal.h>

//const int rs = 1, en = 2, d4 = 3, d5 = 4, d6 = 5, d7 = 6;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int rs = 2, en = 3, d4 = A0, d5 = A1, d6 = A2, d7 = A3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'0','S','D'}
};

byte rowPins[ROWS] = {7,6,5,4}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {10,9,8}; //connect to the column pinouts of the keypad

//byte rowPins[ROWS] = {10,9,8,7}; //connect to the row pinouts of the keypad
//byte colPins[COLS] = {13,12,11}; //connect to the column pinouts of the keypad

//byte rowPins[ROWS] = {10,9,8,7}; //connect to the row pinouts of the keypad
//byte colPins[COLS] = {13,12,11}; //connect to the column pinouts of the key
Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS); 

void setup()
{
  lcd.begin(16, 2);//initializing LCD
  lcd.write("Enter The Number-");
  lcd.setCursor(5,1);
}

void loop()
{
  int i=0;
  char getbyte;
  char key = customKeypad.getKey(); //storing pressed key value in a char
  
  if (key)
  {
    if(key=='D')
    {
      lcd.clear();
      lcd.write("Enter The Number-");
      lcd.setCursor(5,1);
    }
    else if(key!='S')
    {
      lcd.print(key); //showing pressed character on LCD
      getbyte=key;
      //Serial.print(getbyte);
    }
    else
    {
      lcd.clear();
      lcd.write("Enter The Number-");
      lcd.setCursor(5,1);
    }
  }
  
}  
