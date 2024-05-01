#include "MessageQueueInt.h"
#include "Arduino.h"


MessageQueueIntItem::MessageQueueIntItem(TopicMessage* message, MessageQueueIntItem* prev){
    m_message = message;
    m_prev = prev;
    isDirty = false;
}

TopicMessage* MessageQueueIntItem::getMessage(){
    return m_message;
}

MessageQueueIntItem* MessageQueueIntItem::getPrev(){
    return m_prev;
}

void MessageQueueIntItem::setPrev(MessageQueueIntItem* prev){
    this->m_prev = prev;
}

void MessageQueueIntItem::setDirty(bool dirty){
    isDirty = dirty;
}

bool MessageQueueIntItem::getDirty(){
    return isDirty;
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
    if(m_last->getDirty() == false){
        return;
    }
    Serial.println(m_last->getMessage()->getTopic());
    MessageQueueIntItem* target = m_last->getPrev();
    m_last->setPrev(nullptr);

    m_last = target;
    Serial.println("Popped a message");
}

void MessageQueueInt::markLastDirty(){
    if(m_last==nullptr)
        return;
    m_last->setDirty(true);
}

void MessageQueueInt::pushMessage(TopicMessage* message){
    MessageQueueIntItem* newItem = new MessageQueueIntItem(message, m_last);
    m_last = newItem;
}

void MessageQueueInt::pushMessage(int topic, int value){
    this->pushMessage(new TopicMessage(topic, value));
}