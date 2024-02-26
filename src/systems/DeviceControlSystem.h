#include "System.h"
#include "messages/MessageQueueInt.h"
#include "deviceState/DeviceState.h"
#include "messages/Topics.h"

#ifndef DEVICEControlSystem
#define DEVICEControlSystem

class DeviceControlSystem : public System{
    public:
    DeviceControlSystem(MessageQueueInt* messageQueueInt, DeviceState* deviceState);
    virtual void loop();
    private: 
    MessageQueueInt* m_messageQueueInt;
    DeviceState* deviceState;
};

#endif
