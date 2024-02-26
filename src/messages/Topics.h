#ifndef TOPICS
#define TOPICS

typedef int TOPIC;

const int TopicSpeedChange = 0x0001;
const int TopicScreenChange = 0x0002;
const int TopicButtonPressed = 0x0003;
const int TopicBLEChange = 0x0004;

const int LastTopic = TopicBLEChange;

#endif