#include <map>
#include <vector>
#include "messages/Message.h"

#ifndef MESSAGE_BROKER
#define MESSAGE_BROKER

class MessageBroker{
    public: 
        typedef void (*MessageCallbackType)(Message& message);

        void subscribe(int topic, MessageCallbackType callback);
        void broadcast(int topic, Message& message);
    private:
        std::map<int, std::vector<MessageCallbackType>> m_callbacks;
};

#endif