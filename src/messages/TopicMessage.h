#ifndef TOPICMESSAGE
#define TOPICMESSAGE

class TopicMessage{
    public:
    int getTopic();
    int getValue();
    TopicMessage(int topic, int value) : m_topic(topic), m_value(value){}

    private:
    int m_topic;
    int m_value;
};

#endif