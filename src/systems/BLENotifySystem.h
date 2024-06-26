#include "messages/MessageQueueInt.h"
#include "bleService/BLEServer.h"
#include "deviceState/DeviceState.h"
#ifndef BLE_NOTIFY_SYSTEM
#define BLE_NOTIFY_SYSTEM

class BLENotifySystem{
    public:
    BLENotifySystem(
        MessageQueueInt* messageQueue, 
        FanBLEServer* bleServer, 
        DeviceState* deviceState);
    void loop();
    private: 
    MessageQueueInt* m_messageQueue;
    FanBLEServer* m_bleServer;
    DeviceState* m_deviceState;
};

#endif