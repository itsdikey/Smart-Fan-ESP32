#include <map>
#include <vector>
#include "messages/Message.h"
#include "messages/MessageSubscriber.h"
#include <functional>

#ifndef MESSAGE_BROKER
#define MESSAGE_BROKER
class MessageBroker{
    public: 
        

        void subscribe(int topic, MessageSubscriber callback);
        void broadcast(int topic, Message& message);
    private:
        std::map<int, std::vector<MessageSubscriber>> m_callbacks;
};

#endif