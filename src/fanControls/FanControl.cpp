#include "FanControl.h"
#include <Arduino.h>



FanControl::FanControl(MessageQueueInt messageQueue) : m_messageQueue(messageQueue){
};

void FanControl::setSpeed(FanSpeed fanSpeed){
    this->m_fanSpeed = fanSpeed;
}
FanSpeed FanControl::getFanSpeed(){
    return this->m_fanSpeed;
}