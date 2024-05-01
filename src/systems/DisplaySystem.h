#include "messages/MessageQueueInt.h"
#ifndef DISPLAY_SYSTEM
#define DISPLAY_SYSTEM

class DisplaySystem : public System{
    public:
    DisplaySystem(MessageQueueInt* messageQueue);
    void loop();
    private: 
    MessageQueueInt* m_messageQueueInt;
};

#endif