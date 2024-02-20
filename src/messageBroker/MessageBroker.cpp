#include "MessageBroker.h"

void MessageBroker::broadcast(int topic, Message& message){
    if(this->m_callbacks.find(topic) != this->m_callbacks.end())
    {
        for(size_t i =0; i<this->m_callbacks[topic].size(); i++)
        {
            this->m_callbacks[topic][i](message);
        } 
    }
}

void MessageBroker::subscribe(int topic, MessageCallbackType callback){
    if(this->m_callbacks.find(topic) != this->m_callbacks.end())
    {
        m_callbacks[topic].push_back(callback);
    }
    else{
        m_callbacks[topic] = {callback};
    }
}