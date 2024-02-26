
#ifndef MESSAGE_SUBSCRIBER
#define MESSAGE_SUBSCRIBER

#include "Arduino.h"
#include "Topics.h"
#include "Message.h"

class MessageSubscriber {
    public:
    MessageSubscriber(){
        Serial.println("new subscriber");
    }
    virtual ~MessageSubscriber(){}
    virtual void onMessageReceived(TOPIC topic, Message& message){
        Serial.println(topic);
    }
};




#endif