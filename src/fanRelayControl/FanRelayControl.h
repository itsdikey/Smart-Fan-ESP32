#include "models/enums.h"
#include "Arduino.h"

#ifndef FANRELAYCONTROL
#define FANRELAYCONTROL

class FanRelayControl {
    public: 
    FanRelayControl();
    void setSpeed(FanSpeed speed);
    private:
    uint8_t speed1, speed2, speed3;
};

#endif