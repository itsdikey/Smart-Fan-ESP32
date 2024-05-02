#include "ButtonControlSystem.h"
#include "messages/Topics.h"
#include "Arduino.h"


 ButtonControlSystem::ButtonControlSystem(MessageQueueInt* messageQueueInt){
    this->m_messageQueueInt = messageQueueInt;
    this->speedButton->setDebounceTime(10);
    this->canCheck = true;
 }

 void ButtonControlSystem::loop(){
    speedButton->loop();
    Serial.println("button");
    
    if(this->speedButton->isPressed() && canCheck){
        this->m_messageQueueInt->pushMessage(TopicButtonPressed, 1);
        canCheck = false;
        
    Serial.println("pressed");
    }
    if(this->speedButton->isReleased()){
        canCheck = true;
        
        
    Serial.println("released");
    }
 }
