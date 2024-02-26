#include "messages/Topics.h"
#include "SubscriberList.h"
#include "messages/MessageSubscriber.h"
#include "Arduino.h"

#ifndef SUBSCRIPTION_MAP
#define SUBSCRIPTION_MAP

class SubscriptionMap{
    public:
    SubscriptionMap(int maxCount);
    ~SubscriptionMap();
    void add(TOPIC topic, MessageSubscriber& subscriber);
    bool has(TOPIC topic);
    SubscriberList* get(TOPIC topic);
    private: 
    SubscriberList** array;
};
#endif