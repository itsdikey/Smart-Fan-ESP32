#include "MessageQueueInt.h"
#include "Arduino.h"


MessageQueueIntItem::MessageQueueIntItem(TopicMessage* message, MessageQueueIntItem* next){
    m_message = message;
    m_next = next;
    isDirty = false;
}

TopicMessage* MessageQueueIntItem::getMessage(){
    return m_message;
}

MessageQueueIntItem* MessageQueueIntItem::getNext(){
    return m_next;
}

void MessageQueueIntItem::setNext(MessageQueueIntItem* next){
    this->m_next = next;
}

void MessageQueueIntItem::setDirty(bool dirty){
    isDirty = dirty;
}

bool MessageQueueIntItem::getDirty(){
    return isDirty;
}

bool MessageQueueInt::hasMessage(){
    return m_head!=nullptr;
}

TopicMessage* MessageQueueInt::getCurrentMessage(){
    if(m_head==nullptr)
        return nullptr;

    return m_head->getMessage();
}

void MessageQueueInt::popHead(){
    if(m_head==nullptr)
        return;
    if(m_head->getDirty() == false){
        return;
    }
    MessageQueueIntItem* target = m_head->getNext();
    m_head->setNext(nullptr);

    m_head = target;
    Serial.println("Popped a message");
}

void MessageQueueInt::markLastDirty(){
    if(m_head==nullptr)
        return;
    m_head->setDirty(true);
}

void MessageQueueInt::pushMessage(TopicMessage* message){
    if(m_head == nullptr){
        m_head = new MessageQueueIntItem(message, nullptr);
    }
    else{
        MessageQueueIntItem* targetPrev = m_head;

        while(targetPrev->getNext()!=nullptr){
            targetPrev = targetPrev->getNext();
        }

        targetPrev->setNext(new MessageQueueIntItem(message, nullptr));
    }
        
    Serial.println("Push message");
}

void MessageQueueInt::pushMessage(int topic, int value, char from){
    Serial.println(from);
    this->pushMessage(new TopicMessage(topic, value));
}