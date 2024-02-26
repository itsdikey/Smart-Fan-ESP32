#include "messages/MessageQueueInt.h"
#include "models/enums.h"
#ifndef FANCONTROL
#define FANCONTROL

class FanControl{
    public: 
        FanControl(MessageQueueInt messageQueue);
        void setSpeed(FanSpeed fanSpeed);
        FanSpeed getFanSpeed();

    private:
        MessageQueueInt m_messageQueue;
        FanSpeed m_fanSpeed;
};

#endif