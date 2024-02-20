#include "messageBroker/MessageBroker.h"
#include "models/enums.h"
#ifndef FANCONTROL
#define FANCONTROL

class FanControl{
    public: 
        FanControl(MessageBroker messageBroker);
        void setSpeed(FanSpeed fanSpeed);
        FanSpeed getFanSpeed();

    private:
        MessageBroker m_messageBroker;
        FanSpeed m_fanSpeed;
};

#endif