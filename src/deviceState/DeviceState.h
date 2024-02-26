#include "messages/MessageQueueInt.h"
#include "models/enums.h"

#ifndef DEVICE_STATE
#define DEVICE_STATE


class DeviceState{
    private: 
        FanSpeed m_speed;
        ScreenState m_state;
        MessageQueueInt* m_messageQueueInt;

    public: 
        FanSpeed getSpeed();
        void setSpeed(FanSpeed speed);

        ScreenState getScreenState();
        void setScreenState(ScreenState screenState);

        DeviceState(MessageQueueInt* messageQueueInt);
};

#endif