//0-9999 serial moniter to ssd

#include <TimerOne.h>
#include "Timer.h" 

Timer t; // craete a timer object
int del = 5;//Set del as 5; the value is the degree of fine tuning for the clock

long number = 0; 

int first_digit = 0;
int second_digit = 0;
int third_digit = 0;
int fourth_digit = 0;

int timer_event = 0;

int a = 8;
int b = 7;
int c = 6;
int d = 5;
int e = 4;
int f = 3;
int g = 2;
//int p = 9;

int CA_1 = A3;
int CA_2 = A2;
int CA_3 = A1;
int CA_4 = A0;

int count = 0,i,j,num,k1=0;
int digits[4] ;

int CAS[4] = {A0,A1,A2,A3};

//byte numbers[10] {B11111100, B01100000, B11011010, B11110010, B01100110, B10110110, B10111110, B11100000, B11111110, B11110110};

void setup() 
{
  Serial.begin(9600); //serial start and pin config
  pinMode(CA_1, OUTPUT);
  pinMode(CA_2, OUTPUT);
  pinMode(CA_3, OUTPUT);
  pinMode(CA_4, OUTPUT);
  
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

  display_blank();
 
  //Serial.println("please Enter a number from 0 to 9999");
}

void loop() 
{
  t.update(); //timer update
  if (Serial.available()) 
  { 
    //k1++;
    t.stop(timer_event); //stop timer if anythign to read
  
    cathode_high(); // blank the screenw
    
    String s = Serial.readString(); //read the serail value
    
    num=s.length();
    Serial.print(num);    
   number = (long)s.toInt(); //convert it to int
  
   break_number(number);
       /*for (i=0; i<num; i++) 
                    {
                        int temp = digits[0];
                      for (j=0; j<3; j++)
                      {
                        digits[j]=digits[j+1]; 
                      }
                        digits[3] = temp;
                    }
                    num=0;*/
      
      timer_event = t.every(1, display_number); // start timer again
    }
  }
//}

void break_number(long num)
{ 
  first_digit = num / 1000;
  digits[0] = first_digit;

  int first_left = num - (first_digit * 1000);

  second_digit = first_left / 100;
  digits[1] = second_digit;
  int second_left = first_left - (second_digit * 100);
  
  third_digit = second_left / 10;
  digits[2] = third_digit;
  
  fourth_digit = second_left - (third_digit * 10);
  digits[3] = fourth_digit;
}

void display_number() 
{ 
  clearLEDs();//clear the 7-segment display screen
  pickDigit(0);//Light up 7-segment display d1
  pickNumber(digits[0]);// get the value of d1
  delay(del);//delay 5ms

  clearLEDs();//clear the 7-segment display screen
  pickDigit(1);//Light up 7-segment display d2
  pickNumber(digits[1]);// get the value of d2
  delay(del);//delay 5ms

  clearLEDs();//clear the 7-segment display screen
  pickDigit(2);//Light up 7-segment display d3
  pickNumber(digits[2]);//get the value of d3
  delay(del);//delay 5ms

  clearLEDs();//clear the 7-segment display screen
  pickDigit(3);//Light up 7-segment display d4
  pickNumber(digits[3]);//Get the value of d4
  delay(del);//delay 5ms
  
  count++; 
  if (count == 4) 
  { 
    count = 0;
  }
}

void display_blank() 
{ 
  //clearLEDs();
  pickDigit(0);
  pickNumber(0);
  //delay(del);

  //clearLEDs();
  pickDigit(1);
  pickNumber(0); 
  //delay(del);

  //clearLEDs();
  pickDigit(2);
  pickNumber(0);
  //delay(del);

  //clearLEDs();
  pickDigit(3);
  pickNumber(0);
  //delay(del);
}

void pickDigit(int x) //light up a 7-segment display
{
  digitalWrite(CA_1, HIGH);
  digitalWrite(CA_2, HIGH);
  digitalWrite(CA_3, HIGH);
  digitalWrite(CA_4, HIGH);

  switch(x)
  {
    case 0: 
    digitalWrite(CA_1, LOW);//Light d1 up 
    break;
    case 1: 
    digitalWrite(CA_2, LOW); //Light d2 up 
    break;
    case 2: 
    digitalWrite(CA_3, LOW); //Light d3 up 
    break;
    default: 
    digitalWrite(CA_4, LOW); //Light d4 up 
    break;
  }
}

void pickNumber(int x)
{
  switch(x)
  {
    default:zero(); 
    break;
    
    case 1:one(); 
    break;
    
    case 2:two(); 
    break;
    
    case 3:three(); 
    break;
    
    case 4:four(); 
    break;
    
    case 5:five(); 
    break;
    
    case 6:six(); 
    break;
    
    case 7:seven(); 
    break;
    
    case 8:eight(); 
    break;
    
    case 9:nine(); 
    break;
  }
} 

void cathode_high() 
{ //turn off all 4 digits
  digitalWrite(CA_1, HIGH);
  digitalWrite(CA_2, HIGH);
  digitalWrite(CA_3, HIGH);
  digitalWrite(CA_4, HIGH);
}

void clearLEDs() //clear the 7-segment display screen
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
//  digitalWrite(p, HIGH);
}

void zero()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void one() 
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

void two() 
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}
void three()
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void four()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

void five()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void six() 
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void seven() 
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void eight() 
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void nine() 
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}
