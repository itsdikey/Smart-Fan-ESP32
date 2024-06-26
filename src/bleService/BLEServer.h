#ifndef BLE_SERVER
#define BLE_SERVER


#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include "messages/MessageQueueInt.h"
#include "messages/Topics.h"
#include "Arduino.h"

#define SERVICE_UUID        "4e1fd7a0-472e-4fc4-8dad-971c3c585b40" //service
#define SPEED_CHARACTERISTIC_UUID "19fbc35a-0905-4d26-b607-9af309311e85" //speed characteristic
#define ON_OFF_CHARACTERISTIC_UUID "5b80a2f2-5bba-453e-b415-b09f90809195" //on/off
class FanBLEServer{
    public: 
    FanBLEServer(MessageQueueInt* messageQueueInt);
    void setSpeedValue(int value);

    private:
    MessageQueueInt* m_messageQueueInt;
    BLECharacteristic* pCharacteristic;
};

class MyServerCallbacks: public BLEServerCallbacks {
  void onConnect(BLEServer* pServer) {
    Serial.println("connected");
  };
  void onDisconnect(BLEServer* pServer) {
    Serial.println("disconnected");
    BLEDevice::stopAdvertising();
    BLEDevice::startAdvertising();
  }
};

class BleCallbacks: public BLECharacteristicCallbacks {

    public: 
    BleCallbacks(MessageQueueInt* messageQueueInt){
        m_messageQueueInt = messageQueueInt;
    }

    void onWrite(BLECharacteristic *pCharacteristic)
    {
        Serial.println("value received");
        std::string rxValue = pCharacteristic->getValue();
        int value = rxValue[0] - '0';
        Serial.println("write part");
        m_messageQueueInt->pushMessage(TopicBLEChange, value, 'b');
    }

    private: 
    MessageQueueInt* m_messageQueueInt;

};

#endif