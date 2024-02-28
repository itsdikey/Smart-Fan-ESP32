#include "System.h"
#include "messages/MessageQueueInt.h"

#ifndef FANCONTROLSystem
#define FANCONTROLSystem

class FanControlSystem : public System{
    public:
    FanControlSystem(MessageQueueInt* messageQueueInt);

    private: 
    MessageQueueInt* messageQueueInt;
};

#endif
