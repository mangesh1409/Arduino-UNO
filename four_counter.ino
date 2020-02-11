#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8
// Pins driving common anodes
#define CA1 10
#define CA2 11
#define CA3 12
#define CA4 13

// Pins for A B C D E F G, in sequence
const int segs[7] = {2,3,4,5,6,7,8};

// Segments that make each number
const byte numbers[10] ={0b1000000,0b1111001,0b0100100,0b0110000,0b0011001,0b0010010,0b0000010,0b1111000,0b0000000,0b0010000};
 
 
void setup() 
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() 
{
  for (int digit1=0; digit1 < 10; digit1++) 
    {
      for (int digit2=0; digit2 < 10; digit2++) 
        {
          for (int digit3=0; digit3 < 10; digit3++) 
            {
              for (int digit4=0; digit4 < 10; digit4++) 
                {
                    unsigned long startTime = millis();
                    for (unsigned long elapsed=0; elapsed < 600; elapsed = millis() - startTime) 
                      {
                          lightDigit1(numbers[digit1]);
                          delay(5);
                          lightDigit2(numbers[digit2]);
                          delay(5);
                          lightDigit3(numbers[digit3]);
                          delay(5);
                          lightDigit4(numbers[digit4]);
                          delay(5);
                      }
                }
            }
      }
    }
}

void lightDigit1(byte number)     
{
  digitalWrite(CA1, HIGH);
  digitalWrite(CA2, HIGH);
  digitalWrite(CA3, HIGH);
  digitalWrite(CA4, LOW);
  lightSegments(number);
 }
 
void lightDigit2(byte number) 
{
  digitalWrite(CA1, HIGH);
  digitalWrite(CA2, HIGH);
  digitalWrite(CA3, LOW);
  digitalWrite(CA4, HIGH);
  lightSegments(number);
}

void lightDigit3(byte number) 
{
  digitalWrite(CA1, HIGH);
  digitalWrite(CA2, LOW);
  digitalWrite(CA3, HIGH);
  digitalWrite(CA4, HIGH);
  lightSegments(number);
}

void lightDigit4(byte number)
{
  digitalWrite(CA1, LOW);
  digitalWrite(CA2, HIGH);
  digitalWrite(CA3, HIGH);
  digitalWrite(CA4, HIGH);
  lightSegments(number);
 
}

void lightSegments(byte number)
{
  for (int i = 0;i < 7;i++) 
  {
    int bit = bitRead(number, i);
    digitalWrite(segs[i], bit);
  }
}
