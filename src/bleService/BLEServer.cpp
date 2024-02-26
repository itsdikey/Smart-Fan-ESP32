#include "BLEServer.h"
#include <Arduino.h>

FanBLEServer::FanBLEServer(MessageQueueInt* messageQueueInt){
    m_messageQueueInt = messageQueueInt;
    BLEDevice::init("Vivax Smart Fan");
    BLEServer *pServer = BLEDevice::createServer();
    BLEService *pService = pServer->createService(SERVICE_UUID);
    this->pCharacteristic = pService->createCharacteristic(
                                            SPEED_CHARACTERISTIC_UUID,
                                            BLECharacteristic::PROPERTY_READ |
                                            BLECharacteristic::PROPERTY_WRITE |
                                            BLECharacteristic::PROPERTY_NOTIFY
                                        );

    this->pCharacteristic->setValue("0");
    
    this->pCharacteristic->setCallbacks(new BleCallbacks(messageQueueInt));
    pService->start();
    // BLEAdvertising *pAdvertising = pServer->getAdvertising();  // this still is working for backward compatibility
    BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
    pAdvertising->addServiceUUID(SERVICE_UUID);
    pAdvertising->setScanResponse(true);
    pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
    pAdvertising->setMinPreferred(0x12);
    BLEDevice::startAdvertising();
    Serial.println("Characteristic defined! Now you can read it in your phone!");
}

void FanBLEServer::setSpeedValue(int value){
    char valueConverted = '0' + value;

    this->pCharacteristic->setValue(std::string(1, valueConverted));
    this->pCharacteristic->notify(true);
}