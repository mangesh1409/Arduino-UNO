#include <IRremote.h>
#include <IRremoteInt.h>

int RECV_PIN = 9;

int num;
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

IRrecv irrecv(RECV_PIN);

decode_results results;


void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("please Enter a number");
  
  pinMode(CA_4, OUTPUT);

  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

  irrecv.enableIRIn(); // Start the receiver

  digitalWrite(CA_4, LOW);
        zero(); 
}

void loop() 
{
  
  
  if (irrecv.decode(&results)) 
  {    
        Serial.println(results.value,HEX);  
        irrecv.resume();       
        
        //num=results.value,HEX;
        
        //Serial.print(num);
        
    if(results.value==0x40BF00FF)
      {
        digitalWrite(CA_4, LOW);
        zero();        
      }
  

    else if(results.value==0x40BF807F)
      {
        digitalWrite(CA_4, LOW);
        one();        
      }

     else if(results.value==0x40BF40BF)
      {
        digitalWrite(CA_4, LOW);
        two();        
      }

    else if(results.value==0x40BFC03F)
      {
        digitalWrite(CA_4, LOW);
        three();        
      }

     else if(results.value==0x40BF20DF)
      {
        digitalWrite(CA_4, LOW);
        four();        
      }

     else if(results.value==0x40BFA05F)
      {
        digitalWrite(CA_4, LOW);
        five();        
      }

     else if(results.value==0x40BF609F)
      {
       digitalWrite(CA_4, LOW);
        six();        
      }

     else if(results.value==0x40BFE01F)
      {
        digitalWrite(CA_4, LOW);
        seven();        
      }

     else if(results.value==0x40BF10EF)
      {
        digitalWrite(CA_4, LOW);
        eight();        
      }

      else if(results.value==0x40BF906F)
      {
        digitalWrite(CA_4, LOW);
        nine();        
      }

    }
   
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
