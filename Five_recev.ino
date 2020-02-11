#include <TimerOne.h>
#include "Timer.h" 

Timer t; // craete a timer object
int del = 5;//Set del as 5; the value is the degree of fine tuning for the clock

int timer_event = 0;
int count=0;
int digits[1]; 
int digits1[1]; 
int i1=0;

int first_digit = 0;
int second_digit = 0;
int third_digit = 0;
int fourth_digit = 0;

int d1=0;
int d2=0;
int d3=0;
int d4=0;
int d0=0;

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

//int CAS[4] = {10,11,12,13};
int CAS[4] = {A0,A1,A2,A3};

//int rec_byte[4];


 void setup() 
{
  Serial.begin(9600);
  //Serial.println("please Enter a number");
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
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  pinMode(13,INPUT);
  pinMode(A6,INPUT);
 
  display_blank();
}

void loop() 
{
  d0=digitalRead(A6);
  d1=digitalRead(10);
  d2=digitalRead(11);
  d3=digitalRead(12);
  d4=digitalRead(13);

  //if(d0==HIGH)
  //{
    //Serial.print(d0);
       
       if(d1==HIGH&&d2==LOW&&d3==HIGH&&d4==LOW)
        {
          digits1[i1]=0xA;
          digits[i1]=digits1[i1];
         
          
        }
       else if(d1==LOW&&d2==LOW&&d3==LOW&&d4==LOW)
        {
          digits1[i1]=0;
         digits[i1]=digits1[i1];
         
          
          
         }
       else if(d1==HIGH&&d2==LOW&&d3==LOW&&d4==LOW)
        {
          digits1[i1]=1;
          digits[i1]=digits1[i1];
          
          
          
        }
       else if(d1==LOW&&d2==HIGH&&d3==LOW&&d4==LOW)
        {
          digits1[i1]=2;
          digits[i1]=digits1[i1];
          
          
          
        }
       else if(d1==HIGH&&d2==HIGH&&d3==LOW&&d4==LOW)
        {
          digits1[i1]=3;
         digits[i1]=digits1[i1];
          
         
          
        }
       else if(d1==LOW&&d2==LOW&&d3==HIGH&&d4==LOW)
        {
          digits1[i1]=4;
           digits[i1]=digits1[i1];
          
        
         
        }
       else if(d1==HIGH&&d2==LOW&&d3==HIGH&&d4==LOW)
        {
          digits1[i1]=5;
        digits[i1]=digits1[i1];
          
         
          
        }
       else if(d1==LOW&&d2==HIGH&&d3==HIGH&&d4==LOW)
        {
          digits1[i1]=6;
        digits[i1]=digits1[i1];
          
          
         
        }
       else if(d1==HIGH&&d2==HIGH&&d3==HIGH&&d4==LOW)
        {
          digits1[i1]=7;
          digits[i1]=digits1[i1];
          
          
          
        }
       else if(d1==LOW&&d2==LOW&&d3==LOW&&d4==HIGH)
        {
          digits1[i1]=8;
          digits[i1]=digits1[i1];
          
          
         
        }
       else if(d1==HIGH&&d2==LOW&&d3==LOW&&d4==HIGH)
        {
          digits1[i1]=9;
          digits[i1]=digits1[i1];
        }
      
        display_number();
  //}

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
  
  /*count++; 
  if (count == 5) 
  { 
    count = 0;
  }*/
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
