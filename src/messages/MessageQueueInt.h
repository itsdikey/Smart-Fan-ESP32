#include "TopicMessage.h"

#ifndef MESSAGEQUEUEINT
#define MESSAGEQUEUEINT

class MessageQueueIntItem{
    public:
    MessageQueueIntItem(TopicMessage* message, MessageQueueIntItem* prev);
    TopicMessage* getMessage();
    MessageQueueIntItem* getPrev();
    private:
    TopicMessage* m_message;
    MessageQueueIntItem* m_prev;
};

class MessageQueueInt{
    public: 
    void popLast();
    TopicMessage* getCurrentMessage();
    bool hasMessage();
    void pushMessage(TopicMessage* message);
    void pushMessage(int topic, int value);
    private: 
    MessageQueueIntItem* m_last;
};

#endif