int data=A5;

void setup()
{
  Serial.begin(9600);
  pinMode(data,INPUT);
  
}

void loop()
{
  int getbyte=0;
 getbyte=data;
 Serial.println(getbyte); 
}  
