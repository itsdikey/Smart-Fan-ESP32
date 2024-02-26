#include "messages/Message.h"
#include "messages/MessageSubscriber.h"
#include "SubscriptionMap.h"

#ifndef MESSAGE_BROKER
#define MESSAGE_BROKER
class MessageBroker{
    public:
        MessageBroker(TOPIC maxTopic);
        void subscribe(int topic, MessageSubscriber& callback);
        void broadcast(int topic, Message& message);
    private:
        SubscriptionMap* callbackMap;
};

#endif