#include "System.h"
#include "messageBroker/MessageBroker.h"

#ifndef FANCONTROLSystem
#define FANCONTROLSystem

class FanControlSystem : public System{
    public:
    FanControlSystem(MessageBroker* messageBroker);

    private: 
    MessageBroker* messageBroker;
};

#endif
