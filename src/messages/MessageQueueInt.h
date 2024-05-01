#include "TopicMessage.h"

#ifndef MESSAGEQUEUEINT
#define MESSAGEQUEUEINT

class MessageQueueIntItem{
    public:
    MessageQueueIntItem(TopicMessage* message, MessageQueueIntItem* prev);
    TopicMessage* getMessage();
    MessageQueueIntItem* getPrev();
    void setPrev(MessageQueueIntItem* prev);
    void setDirty(bool dirty);
    bool getDirty();
    private:
    TopicMessage* m_message;
    MessageQueueIntItem* m_prev;
    bool isDirty;
};

class MessageQueueInt{
    public: 
    void popLast();
    TopicMessage* getCurrentMessage();
    bool hasMessage();
    void pushMessage(TopicMessage* message);
    void pushMessage(int topic, int value);
    void markLastDirty();
    private: 
    MessageQueueIntItem* m_last;
};

#endif