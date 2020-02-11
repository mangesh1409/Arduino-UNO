#include <IRremote.h>
#include <IRremoteInt.h>

#include <TimerOne.h>
#include "Timer.h" 

Timer t; // craete a timer object
int del = 5;//Set del as 5; the value is the degree of fine tuning for the clock

int timer_event = 0;
int count=0;
int digits[4], digits1[4] ;

int i,j,k=0;

long number = 0; 

int first_digit = 0;
int second_digit = 0;
int third_digit = 0;
int fourth_digit = 0;

/*8const unsigned long hex_code1[10]={0x38C700FF,
                                  0x38C7807F,
                                  0x38C740BF,
                                  0x38C7C03F,
                                  0x38C720DF,
                                  0x38C7A05F,
                                  0x38C7609F,
                                  0x38C7E01F,
                                  0x38C710EF,
                                  0x38C7906F
                                 };*/

const unsigned long hex_code2[10]={0x2FD00FF,
                                  0x2FD807F,
                                  0x2FD40BF,
                                  0x2FDC03F,
                                  0x2FD20DF,
                                  0x2FDA05F,
                                  0x2FD609F,
                                  0x2FDE01F,
                                  0x2FD10EF,
                                  0x2FD906F
                                 };             
                                 
//int switch1 = A0;
//int switch2 = A1;
//int Value = 0;

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

int CAS[4] = {10,11,12,13};

int RECV_PIN = 9;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() 
{
  Serial.begin(9600);
  //Serial.println("please Enter a number");
  pinMode(RECV_PIN, INPUT);
  //pinMode(switch1, INPUT);

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

  irrecv.enableIRIn(); // Start the receiver
}

void loop() 
{
    // t.update(); //timer update
    //Value = analogRead(switch1);
    // Serial.print(sensorValue);
    
    //if(Value==1023)
      //{
          display_number();
          if (irrecv.decode(&results)) 
          {    
            //t.stop(timer_event); //stop timer if anythign to read
            //   cathode_high(); // blank the screen
      
            //Serial.println(results.value,HEX);         
            //irrecv.resume();

            //if(results.value!=0x38C730CF)
            if(results.value!=0x2FD30CF)
            
            //if((results.value!=0x2FD30CF)|(results.value!=0x38C730CF))
              {
                for(j=0;j<=9;j++)
                  {
                    //if((results.value==hex_code1[j])|(results.value==hex_code2[j]))
                    if(results.value==hex_code2[j])
                      {
                        //Serial.println(k);
                        digits1[k]=j;
                        //Serial.println(digits1[k]);
                        k++;
                        //  if (k==5)
                        // { k =0 ; }
                      }
                  }
              }

            else
              {    
                if (k !=0)
                  {  
                    for(i=0;i<=3;i++)
                      {
                        //Serial.println(digits[i]);
                        digits[i] = digits1[i];
                        digits1[i] = 0;
                      } 
         
                  for (i=0; i<k; i++) 
                    {
                        int temp = digits[0];
                      for (j=0; j<3; j++)
                      {
                        digits[j]=digits[j+1]; 
                      }
                        digits[3] = temp;
                    }
                  }

                  k=0;
             
              }
        irrecv.resume(); 
        }
}

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
