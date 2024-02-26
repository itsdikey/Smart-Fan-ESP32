#include "MessageBroker.h"

void MessageBroker::broadcast(TOPIC topic, Message& message){
    if(this->m_callbacks.find(topic) != this->m_callbacks.end())
    {
        for(size_t i =0; i<this->m_callbacks[topic].size(); i++)
        {
            this->m_callbacks[topic][i].onMessageReceived(topic, message);
        } 
    }
}

void MessageBroker::subscribe(TOPIC topic, MessageSubscriber callback){
    if(this->m_callbacks.find(topic) != this->m_callbacks.end())
    {
        m_callbacks[topic].push_back(callback);
    }
    else{
        m_callbacks[topic] = {callback};
    }
}