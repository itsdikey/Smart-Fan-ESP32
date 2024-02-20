#include "FanControl.h"
#include <Arduino.h>



FanControl::FanControl(MessageBroker messageBroker){
    this->m_messageBroker = messageBroker;
}

void FanControl::setSpeed(FanSpeed fanSpeed){
    this->m_fanSpeed = fanSpeed;
}
FanSpeed FanControl::getFanSpeed(){
    return this->m_fanSpeed;
}