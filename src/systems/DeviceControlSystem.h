#include "System.h"
#include "messageBroker/MessageBroker.h"
#include "deviceState/DeviceState.h"
#include "messages/Topics.h"

#ifndef DEVICEControlSystem
#define DEVICEControlSystem

class DeviceControlSystem : public System{
    public:
    DeviceControlSystem(MessageBroker* messageBroker, DeviceState* deviceState);
    virtual void loop();
    private: 
    MessageBroker* messageBroker;
    DeviceState* deviceState;
};

#endif
