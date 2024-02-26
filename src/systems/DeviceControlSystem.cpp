#include "DeviceControlSystem.h"
#include "messages/MessageSubscriber.h"
#include "Arduino.h"




DeviceControlSystem::DeviceControlSystem(MessageQueueInt* messageQueueInt, DeviceState* deviceState){

    
    this->m_messageQueueInt = messageQueueInt;
    this->deviceState = deviceState;

   

    Serial.println("Pre Subscribe");
    //messageBroker->subscribe(TopicBLEChange, deviceControlSystemSubscriber);
    // messageBroker->subscribe(TopicButtonPressed, *deviceControlSystemSubscriber);
}

void DeviceControlSystem::loop(){
    if(!m_messageQueueInt->hasMessage())
        return;
    switch (m_messageQueueInt->getCurrentMessage()->getTopic())
    {
    case TopicBLEChange:
        Serial.println("TopicBLEChange changed");
        break;

    case TopicButtonPressed:
        Serial.println("TopicButtonPressed changed");
    break;
    
    default:
        break;
    }
}


