#include "DeviceControlSystem.h"
#include "messages/MessageSubscriber.h"
#include "Arduino.h"

DeviceControlSystem::DeviceControlSystem(MessageBroker* messsageBroker, DeviceState* deviceState){

    class DeviceControlSystemSubscriber : public MessageSubscriber { 
        void onMessageReceived(TOPIC topic, Message& message){
            Serial.println(topic);
        }
    };

    this->messageBroker = messageBroker;
    this->deviceState = deviceState;

    DeviceControlSystemSubscriber* deviceControlSystemSubscriber = new DeviceControlSystemSubscriber();
    //MessageCallbackType callback = &DeviceControlSystem::onBLEChange;
    
    messageBroker->subscribe(TopicBLEChange, *deviceControlSystemSubscriber);
    messageBroker->subscribe(TopicButtonPressed, *deviceControlSystemSubscriber);
}

void DeviceControlSystem::loop(){

}


