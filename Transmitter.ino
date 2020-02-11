#include <Keypad.h>
#include <LiquidCrystal.h>

int data=A0;

const int rs = 1, en = 2, d4 = A0, d5 = A1, d6 = A2, d7 = A3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'0','S','D'}
};

byte rowPins[ROWS] = {6,5,4,3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9,8,7}; //connect to the column pinouts of the keypad

//byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
//byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

//byte rowPins[ROWS] = {10,9,8,7}; //connect to the row pinouts of the keypad
//byte colPins[COLS] = {13,12,11}; //connect to the column pinouts of the keypad

Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS); 

void setup()
{
  pinMode(data,OUTPUT);
  lcd.begin(16, 2);//initializing LCD
  lcd.write("Enter The Number-");
  lcd.setCursor(5,1);
}

void loop()
{
  int i=0;
  int sendbyte;
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
      sendbyte=key;
      
      //Serial.print(getbyte);
    }
    else
    {
      lcd.clear();
      lcd.write("Enter The Number-");
      lcd.setCursor(5,1);
      data=sendbyte;
    }
  }
  
}
