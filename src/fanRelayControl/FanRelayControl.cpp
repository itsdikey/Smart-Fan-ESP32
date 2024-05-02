#include "FanRelayControl.h"
#include "Arduino.h"

FanRelayControl::FanRelayControl():speed1(1), speed2(2), speed3(3){
    pinMode(speed1, OUTPUT);
    pinMode(speed2, OUTPUT);
    pinMode(speed3, OUTPUT);
    setSpeed(Speed0);
}

void FanRelayControl::setSpeed(FanSpeed fanSpeed){
    if(fanSpeed == Speed0){
        digitalWrite(speed1, LOW);
        digitalWrite(speed2, LOW);
        digitalWrite(speed3, LOW);
    } else if(fanSpeed == Speed1){
        digitalWrite(speed1, HIGH);
        digitalWrite(speed2, LOW);
        digitalWrite(speed3, LOW);
    } else if(fanSpeed == Speed2){
        digitalWrite(speed1, LOW);
        digitalWrite(speed2, HIGH);
        digitalWrite(speed3, LOW);
    } else if(fanSpeed == Speed3){
        digitalWrite(speed1, LOW);
        digitalWrite(speed2, LOW);
        digitalWrite(speed3, HIGH);
    }
}