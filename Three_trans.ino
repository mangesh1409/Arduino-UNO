#include <Keypad.h>
#include <LiquidCrystal.h>

//const int rs = 1, en = 2, d4 = 3, d5 = 4, d6 = 5, d7 = 6;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

char getbyte[6];
int i=1;
char key=0;
//int d1=11;
//int d2=12;
//int d3=13;
//int d=A4;

const int rs = A0, en = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'0','S','D'}
};

//byte rowPins[ROWS] = {8,7,4,2}; //connect to the row pinouts of the keypad
//byte colPins[COLS] = {12,11,10}; //connect to the column pinouts of the keypad

byte rowPins[ROWS] = {10,9,8,7}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {13,12,11}; //connect to the column pinouts of the keypad

Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS); 
void setup()
{
    Serial.begin(9600);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    Serial.print("Enter number-");
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
      getbyte[0]='A';
      for(int k=1;k<=4;k++)
      {
        getbyte[k]='0';
      }
      getbyte[5]='E' ;
      lcd.clear();
      lcd.write("Enter The Number-");
      lcd.setCursor(5,1);
    }
    else if(key!='S')
    {
      getbyte[0]='A';
      lcd.print(key); //showing pressed character on LCD
      getbyte[i]=key;
      i++;
      Serial.println(key);
    }
    else
    {
     getbyte[5]='E' ;
      for(int a=0;a<=5;a++)
      {
     Serial.println(getbyte[a]);
      }
      i=1;
      for(int j=0;j<=5;j++)
        {
             char x1=getbyte[j];
             Serial.println(x1);

             switch(x1)
             {
              case 'A':digitalWrite(2,LOW); 
                     digitalWrite(3,HIGH);
                     digitalWrite(4,LOW);
                     digitalWrite(5,HIGH);  
                     break;
              case '0':digitalWrite(2,LOW);
                     digitalWrite(3,LOW);
                     digitalWrite(4,LOW);
                     digitalWrite(5,LOW);  
                     break;
              case '1':digitalWrite(2,HIGH);
                     digitalWrite(3,LOW);
                     digitalWrite(4,LOW);
                     digitalWrite(5,LOW);
                     break;
              case '2':digitalWrite(2,LOW);
                     digitalWrite(3,HIGH);
                     digitalWrite(4,LOW);
                     digitalWrite(5,LOW);
                     break;
              case '3':digitalWrite(2,HIGH);
                     digitalWrite(3,HIGH);
                     digitalWrite(4,LOW);
                     digitalWrite(5,LOW);
                     break;
              case '4':digitalWrite(2,LOW);
                     digitalWrite(3,LOW);
                     digitalWrite(4,HIGH);
                     digitalWrite(5,LOW);
                     break;
              case '5':digitalWrite(2,HIGH);
                     digitalWrite(3,LOW);
                     digitalWrite(4,HIGH);
                     digitalWrite(5,LOW);
                     break;
              case '6':digitalWrite(2,LOW);
                     digitalWrite(3,HIGH);
                     digitalWrite(4,HIGH);
                     digitalWrite(5,LOW);
                     break;
              case '7':digitalWrite(2,HIGH);
                     digitalWrite(3,HIGH);
                     digitalWrite(4,HIGH);
                     digitalWrite(5,LOW);
                     break;
              case '8':digitalWrite(2,LOW);
                     digitalWrite(3,LOW);
                     digitalWrite(4,LOW);
                     digitalWrite(5,HIGH);
                     break;
              case '9':digitalWrite(2,HIGH);
                     digitalWrite(3,LOW);
                     digitalWrite(4,LOW);
                     digitalWrite(5,HIGH);
                     break;
               case 'E':digitalWrite(2,LOW);
                     digitalWrite(3,HIGH);
                     digitalWrite(4,HIGH);
                     digitalWrite(5,HIGH);  
                     break;
              
             }
             //delay(2000);
       }

     lcd.clear();
      lcd.write("Enter The Number-");
      lcd.setCursor(5,1);
      for(int k1=1;k1<=4;k1++)
      {
        getbyte[k1]='0';
      }
    }
  }
  
}
