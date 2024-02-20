#include "DeviceState.h"
#include "messages/Topics.h"
#include "messages/ValueMessage.h"

FanSpeed DeviceState::getSpeed(){
    return this->m_speed;
}

void DeviceState::setSpeed(FanSpeed speed){
    this->m_speed = speed;
    ValueMessage<FanSpeed>* message = new ValueMessage<FanSpeed>(speed);
    m_messageBroker->broadcast(TopicSpeedChange, *message);
}

ScreenState DeviceState::getScreenState(){
    return this->m_state;
}

void DeviceState::setScreenState(ScreenState state){
    this->m_state = state;
     ValueMessage<ScreenState>* message = new ValueMessage<ScreenState>(state);
    m_messageBroker->broadcast(TopicScreenChange, *message);
}

DeviceState::DeviceState(MessageBroker* messageBroker){
    this->m_messageBroker = messageBroker;
}

