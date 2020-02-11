/*#include <IRremote.h>
#include <IRremoteInt.h>

int RECV_PIN = 9; 
 unsigned long a;

IRrecv irrecv(RECV_PIN);

decode_results results;


void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("please Enter a number");
  pinMode(RECV_PIN, INPUT);

  irrecv.enableIRIn(); // Start the receiver
}


void loop() 
{
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)) 
  {     
        Serial.println(results.value,HEX);  
        
        a=(0x000FFFF&results.value);
        //long unsigned int number =(long)a.to HEX();
        
        ///Serial.println(number);
        
        irrecv.resume();
  }
}*/

#include <IRremote.h>
#include <IRremoteInt.h>

//int RECV_PIN = 8;
int RECV_PIN = A5;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  pinMode(RECV_PIN, INPUT);
  Serial.println("please Enter a number");
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) 
  {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
}
