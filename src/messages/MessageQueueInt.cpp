#include "MessageQueueInt.h"


MessageQueueIntItem::MessageQueueIntItem(TopicMessage* message, MessageQueueIntItem* prev){
    m_message = message;
    m_prev = prev;
}

TopicMessage* MessageQueueIntItem::getMessage(){
    return m_message;
}

MessageQueueIntItem* MessageQueueIntItem::getPrev(){
    return m_prev;
}

bool MessageQueueInt::hasMessage(){
    return m_last!=nullptr;
}

TopicMessage* MessageQueueInt::getCurrentMessage(){
    if(m_last==nullptr)
        return nullptr;

    return m_last->getMessage();
}

void MessageQueueInt::popLast(){
    if(m_last==nullptr)
        return;
    m_last = m_last->getPrev();
}

void MessageQueueInt::pushMessage(TopicMessage* message){
    MessageQueueIntItem* newItem = new MessageQueueIntItem(message, m_last);
    m_last = newItem;
}

void MessageQueueInt::pushMessage(int topic, int value){
    this->pushMessage(new TopicMessage(topic, value));
}