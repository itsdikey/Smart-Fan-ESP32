#include "DeviceState.h"
#include "messages/Topics.h"
#include "messages/ValueMessage.h"

FanSpeed DeviceState::getSpeed(){
    return this->m_speed;
}

void DeviceState::setSpeed(FanSpeed speed){
    this->m_speed = speed;
    m_messageQueueInt->pushMessage(TopicSpeedChange, speed, 's');
}

ScreenState DeviceState::getScreenState(){
    return this->m_state;
}

void DeviceState::setScreenState(ScreenState state){
    this->m_state = state;
     ValueMessage<ScreenState>* message = new ValueMessage<ScreenState>(state);
    
    m_messageQueueInt->pushMessage(TopicScreenChange, state, 'k');
}

DeviceState::DeviceState(MessageQueueInt* messageBroker){
    this->m_messageQueueInt = messageBroker;
    this->setSpeed(Speed0);
    this->setScreenState(On);
}

