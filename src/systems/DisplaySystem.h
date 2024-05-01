#include "System.h"
#include "messages/MessageQueueInt.h"
#include "deviceState/DeviceState.h"
#ifndef DISPLAY_SYSTEM
#define DISPLAY_SYSTEM

class DisplaySystem : public System{
    public:
    DisplaySystem(DeviceState* deviceState);
    void loop();
    private: 
    DeviceState* m_deviceState;
    long lastChange;
    const long maxChange = 15000;
    FanSpeed m_lastSpeed;
};

#endif