#include "SubscriptionMap.h"

SubscriptionMap::SubscriptionMap(int maxCount){
    array = new SubscriberList*[maxCount];
}

SubscriptionMap::~SubscriptionMap(){
    delete array;
}

bool SubscriptionMap::has(TOPIC topic){
    Serial.println("has called");
    return array[topic] != nullptr;
}

void SubscriptionMap::add(TOPIC topic, MessageSubscriber& subscriber){
    Serial.println("Add called");
    if(!this->has(topic)) {
        Serial.println("No topic");
        array[topic] = new SubscriberList();
    }
    array[topic]->addBack(subscriber);
}

SubscriberList* SubscriptionMap::get(TOPIC topic){
    return array[topic];
}
