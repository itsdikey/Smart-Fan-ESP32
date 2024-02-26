#include "ButtonControlSystem.h"

ButtonControlSystem::ButtonControlSystem(MessageQueueInt* messageQueueInt)
{
    m_messageQueueInt = messageQueueInt;
    speed_1Button = ezButton(1);
    speed_2Button = ezButton(2);
    speed_3Button = ezButton(3);
}

void ButtonControlSystem::loop(){
    if(speed_1Button.isReleased()){
        m_messageQueueInt->pushMessage(TopicButtonPressed, 1);
        return;
    }
    
    if(speed_2Button.isReleased()){
        m_messageQueueInt->pushMessage(TopicButtonPressed, 2);
        return;
    }

    if(speed_3Button.isReleased()){
        m_messageQueueInt->pushMessage(TopicButtonPressed, 3);
        return;
    }
}