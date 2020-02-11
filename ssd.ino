#include "SevSeg.h"
SevSeg sevseg; 

void setup()
{
    pinMode(9, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    
    byte numDigits = 1;
    byte digitPins[] = {};
    byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8};
    bool resistorsOnSegments = true;

    byte hardwareConfig = COMMON_ANODE; 
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);
}

void loop()
{
    /*digitalWrite(9, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);*/
    
    for(int i = 0; i < 10; i++){
        sevseg.setNumber(i);
        delay(1000);
        sevseg.refreshDisplay(); 
        }
}
