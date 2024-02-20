#include "ButtonControlSystem.h"

ButtonControlSystem::ButtonControlSystem(MessageBroker* messageBroker)
{
    m_messageBroker = messageBroker;
    speed_1Button = ezButton(1);
    speed_2Button = ezButton(2);
    speed_3Button = ezButton(3);
}

void ButtonControlSystem::loop(){
    if(speed_1Button.isReleased()){
        ValueMessage<int>* message = new ValueMessage<int>(1);
        m_messageBroker->broadcast(TopicButtonPressed, *message);
        return;
    }
    
    if(speed_2Button.isReleased()){
        ValueMessage<int>* message = new ValueMessage<int>(2);
        m_messageBroker->broadcast(TopicButtonPressed, *message);
        return;
    }

    if(speed_3Button.isReleased()){
        ValueMessage<int>* message = new ValueMessage<int>(3);
        m_messageBroker->broadcast(TopicButtonPressed, *message);
        return;
    }
}