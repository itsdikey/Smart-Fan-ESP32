
#ifndef MESSAGE_SUBSCRIBER
#define MESSAGE_SUBSCRIBER

#include "Topics.h"
#include "Message.h"

class MessageSubscriber {
    public:
    virtual ~MessageSubscriber();
    virtual void onMessageReceived(TOPIC topic, Message& message);
};

#endif