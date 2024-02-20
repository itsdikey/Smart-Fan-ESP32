#include "messageBroker/MessageBroker.h"
#include "models/enums.h"

#ifndef DEVICE_STATE
#define DEVICE_STATE


class DeviceState{
    private: 
        FanSpeed m_speed;
        ScreenState m_state;
        MessageBroker* m_messageBroker;

    public: 
        FanSpeed getSpeed();
        void setSpeed(FanSpeed speed);

        ScreenState getScreenState();
        void setScreenState(ScreenState screenState);

        DeviceState(MessageBroker* messageBroker);
};

#endif