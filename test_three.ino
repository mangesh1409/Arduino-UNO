#include <IRremote.h>
#include <IRremoteInt.h>

int RECV_PIN = 9;

IRrecv irrecv(RECV_PIN);
decode_results results;

int i,j,a[4],k=0;

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

void setup() 
{
  Serial.begin(9600);
  Serial.println("please Enter a number");
  pinMode(RECV_PIN, INPUT);

  irrecv.enableIRIn(); // Start the receiver
}

void loop() 
{
  
  if (irrecv.decode(&results)) 
    {   //k=0; 
      Serial.println(results.value,HEX);         
      irrecv.resume();

      if(results.value!=0x40BF30CF)
      {
        for(j=0;j<=9;j++)
          {
            if(results.value==hex_code[j])
              {
                Serial.println(k);
                a[k]=j;
                Serial.println(a[k]);
                k++;
              }
          }
      }
      
      else
      {    
        k=0;  
        for(i=0;i<=3;i++)
          {
            Serial.println(a[i]);
          }
        for(i=0;i<=3;i++)
        {
          a[i]=0;
        }
      }
    }
  }
