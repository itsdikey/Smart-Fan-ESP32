#include "TopicMessage.h"

#ifndef MESSAGEQUEUEINT
#define MESSAGEQUEUEINT

class MessageQueueIntItem{
    public:
    MessageQueueIntItem(TopicMessage* message, MessageQueueIntItem* next);
    TopicMessage* getMessage();
    MessageQueueIntItem* getNext();
    void setNext(MessageQueueIntItem* next);
    void setDirty(bool dirty);
    bool getDirty();
    private:
    TopicMessage* m_message;
    MessageQueueIntItem* m_next;
    bool isDirty;
};

class MessageQueueInt{
    public: 
    void popHead();
    TopicMessage* getCurrentMessage();
    bool hasMessage();
    void pushMessage(TopicMessage* message);
    void pushMessage(int topic, int value, char from = 'd');
    void markLastDirty();
    private: 
    MessageQueueIntItem* m_head;
};

#endif