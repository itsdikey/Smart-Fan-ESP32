#ifndef BLE_SERVER
#define BLE_SERVER


#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include "messageBroker/MessageBroker.h"
#include "messages/Topics.h"
#include "messages/ValueMessage.h"

#define SERVICE_UUID        "4e1fd7a0-472e-4fc4-8dad-971c3c585b40" //service
#define SPEED_CHARACTERISTIC_UUID "19fbc35a-0905-4d26-b607-9af309311e85" //speed characteristic
#define ON_OFF_CHARACTERISTIC_UUID "5b80a2f2-5bba-453e-b415-b09f90809195" //on/off
class FanBLEServer{
    public: 
    FanBLEServer(MessageBroker* messageBroker);
    void setSpeedValue(int value);

    private:
    MessageBroker* m_messageBroker;
    BLECharacteristic* pCharacteristic;
};

class BleCallbacks: public BLECharacteristicCallbacks {

    public: 
    BleCallbacks(MessageBroker* messageBroker){
        m_messageBroker = messageBroker;
    }

    void onWrite(BLECharacteristic *pCharacteristic)
    {
        std::string rxValue = pCharacteristic->getValue();
        int value = rxValue[0] - '0';
        ValueMessage<int>* message = new ValueMessage<int>(value);
        m_messageBroker->broadcast(TopicBLEChange, *message);
    }

    private: 
    MessageBroker* m_messageBroker;

};

#endif