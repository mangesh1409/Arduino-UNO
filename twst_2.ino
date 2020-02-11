#include <IRremote.h>
#include <IRremoteInt.h>

#include <TimerOne.h>
#include "Timer.h" 

Timer t; // craete a timer object
int del = 5;//Set del as 5; the value is the degree of fine tuning for the clock

int RECV_PIN = 9;

IRrecv irrecv(RECV_PIN);
decode_results results;

int i,j;

int number[4]={0,0,0,0};

const unsigned long hex_code[10]={0x40BF00FF,
                                0x40BF807F,
                                0x40BF40BF,
                                0x40BFC03F,
                                0x40BF20DF,
                                0x40BFA05F,
                                0x40BF609F,
                                0x40BFE01F,
                                0x40BF10EF,
                                0x40BF906F
                                };

int a = 8;
int b = 7;
int c = 6;
int d = 5;
int e = 4;
int f = 3;
int g = 2;
//int p = 9;

int CA_1 = 13;
int CA_2 = 12;
int CA_3 = 11;
int CA_4 = 10;

//int count = 0;
int timer_event = 0;

int CAS[4] = {10,11,12,13};

void setup() 
{
  Serial.begin(9600);
  Serial.println("please Enter a number");
  pinMode(RECV_PIN, INPUT);

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

  //int number[4]={0,0,0,0,};
  
  irrecv.enableIRIn(); // Start the receiver
}

void loop() 
{
  unsigned long recv_value;
  cathode_high(); // blank the screen

    for(i=0;i<=3;i++)
      {
        t.update(); //timer update
  
        if (irrecv.decode(&results)) 
          {    
            t.stop(timer_event); //stop timer if anythign to read
            //cathode_high(); // blank the screen
            Serial.println(results.value,HEX);         
            irrecv.resume();
            //recv_value=results.value;
        
            if(results.value!=0x40BF30CF)
              { 
                for(j=0;j<=9;j++)
                {
                  if(results.value==hex_code[j])
                       {
                          number[i]=j;
                          delay(200);
                        }
                 }
              }
                                
            else
          {
            //timer_event = t.every(1, display_number); // start timer again
            display_number();
          }
     }
    //irrecv.resume();
  }
}     

void display_number() 
{ 
  clearLEDs();//clear the 7-segment display screen
  pickDigit(0);//Light up 7-segment display d1
  pickNumber(number[0]);// get the value of d1
  delay(del);//delay 5ms

  clearLEDs();//clear the 7-segment display screen
  pickDigit(1);//Light up 7-segment display d2
  pickNumber(number[1]);// get the value of d2
  delay(del);//delay 5ms

  clearLEDs();//clear the 7-segment display screen
  pickDigit(2);//Light up 7-segment display d3
  pickNumber(number[2]);//get the value of d3
  delay(del);//delay 5ms

  clearLEDs();//clear the 7-segment display screen
  pickDigit(3);//Light up 7-segment display d4
  pickNumber(number[3]);//Get the value of d4
  delay(del);//delay 5ms
  
  /*count++; 
  if (count == 4) 
  { 
    count = 0;
  }*/
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
