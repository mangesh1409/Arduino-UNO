#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8

// Pins driving common anodes
#define CA1 10

// Pins for A B C D E F G, in sequence
const int segs[7] = {2,3,4,5,6,7,8};

// Segments that make each number
const byte numbers[10] = { 0b1000000, 0b1111001,0b0100100, 0b0110000, 0b0011001, 0b0010010, 0b0000010,0b1111000, 0b0000000, 0b0010000};

int digit1;
int val1;
int i;

void setup() 
{
  Serial.begin(9600);
  lightDigit1(numbers[0]);
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);  
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
 
}

void loop() 
{
  if (Serial.available()>0) 
  {
      digit1= Serial.read();
      val1=digit1&0x0f;
      Serial.write(digit1);
      lightDigit1(numbers[val1]);

      

      //for(i=0;i<=9;i++)
      //{
      //lightDigit1(numbers[i]);
       //delay(1000);
      //}   
      /*if(val1=='0')
      {
         lightDigit1(numbers[0]);
        delay(5);
      }
      
      else if(val1=='1')
      {
         lightDigit1(numbers[1]);
        delay(5);
      }

      else if(val1=='2')
      {
         lightDigit1(numbers[2]);
        delay(5);
      }

      else if(val1=='3')
      {
         lightDigit1(numbers[3]);
        delay(5);
      }

      else if(val1=='4')
      {
         lightDigit1(numbers[4]);
        delay(5);
      }

      else if(val1=='5')
      {
         lightDigit1(numbers[5]);
        delay(5);
      }

      else if(val1=='6')
      {
         lightDigit1(numbers[6]);
        delay(5);
      }

      else if(val1=='7')
      {
         lightDigit1(numbers[7]);
        delay(5);
      }

      else if(val1=='8')
      {
         lightDigit1(numbers[8]);
        delay(5);
      }

      else if(val1=='9')
      {
         lightDigit1(numbers[9]);
        delay(5);
      }*/
  }
}

void lightDigit1(byte number) 
{
  digitalWrite(CA1, LOW);
  lightSegments(number);
}

void lightSegments(byte number) 
{
  for (int i = 0; i < 7; i++) 
  {
    int bit = bitRead(number, i);
    digitalWrite(segs[i], bit);
  }
}
