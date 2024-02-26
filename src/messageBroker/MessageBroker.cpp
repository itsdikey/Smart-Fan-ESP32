#include "MessageBroker.h"
#include "messages/ValueMessage.h"
#include "Arduino.h"

MessageBroker::MessageBroker(TOPIC maxTopic){
    callbackMap = new SubscriptionMap(maxTopic);
}


void MessageBroker::broadcast(TOPIC topic, Message& message){
    // if(this->callbackMap->has(topic)){
    //     SubscriberListIterator* iterator = this->callbackMap->get(topic)->iterator();

    //     while(iterator->hasMore()){
    //         iterator->getNext()->value->onMessageReceived(topic, message);
    //     }
    // }
}

void MessageBroker::subscribe(TOPIC topic, MessageSubscriber& callback){
    Serial.println("Subscribe trying");
    Serial.println("Just checking");
    Serial.println(callbackMap==nullptr?"Null":"Not Null");
    Message* x = new ValueMessage<int>(10);
    callback.onMessageReceived(123, *x);
    callbackMap->add(topic, callback);
    Serial.println("Subscribtion added");
}