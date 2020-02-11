#include <Keypad.h>
#include <LiquidCrystal.h>

char getbyte[4];
char key='0';
int i;

const int rs = A0, en = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {   {'1','2','3'},
                            {'4','5','6'},
                            {'7','8','9'},
                            {'0','S','D'}
                         };

byte rowPins[ROWS] = {10,9,8,7}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {13,12,11}; //connect to the column pinouts of the keypad

Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS); 

void setup()
{
    Serial.begin(9600);
   // Serial.print("Enter number-");
    lcd.begin(16, 2);//initializing LCD
    lcd.write("Enter The Number-");
    lcd.setCursor(5,1);
}

void loop()
{
  key = customKeypad.getKey(); //storing pressed key value in a char
  
  if (key)
  {
    
    if(key=='D')
    {
      i=0;
      for(int k=0;k<=1;k++)
      {
        getbyte[k]='0';
      }
      
      lcd.clear();
      lcd.write("Enter The Number-");
      lcd.setCursor(5,1);
    }
     
    else if(key!='S')
    {
      lcd.print(key); //showing pressed character on LCD
      getbyte[i]=key;
      i++;
      //Serial.println(key);
    }
    
    else
    {
      //i=0;
      for(int j=0;j<i;j++)
        {
             char x1=getbyte[j];
             Serial.write(x1);
        }
        
      lcd.clear();
      lcd.write("Enter The Number-");
      lcd.setCursor(5,1);
      i=0;
      for(int k1=0;k1<=3;k1++)
      {
        getbyte[k1]='0';
      }
    }
  }
  
}
