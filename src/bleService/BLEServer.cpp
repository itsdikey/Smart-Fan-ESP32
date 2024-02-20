#include "BLEServer.h"



FanBLEServer::FanBLEServer(MessageBroker* messageBroker){
    m_messageBroker = messageBroker;
    BLEDevice::init("Vivax Smart Fan");
    BLEServer *pServer = BLEDevice::createServer();
    BLEService *pService = pServer->createService(SERVICE_UUID);
    BLECharacteristic *pCharacteristic = pService->createCharacteristic(
                                            SPEED_CHARACTERISTIC_UUID,
                                            BLECharacteristic::PROPERTY_READ |
                                            BLECharacteristic::PROPERTY_WRITE
                                        );

    pCharacteristic->setValue(0);
    
   // pCharacteristic->setCallbacks(new BleCallbacks(messageBroker));
    pService->start();
    // BLEAdvertising *pAdvertising = pServer->getAdvertising();  // this still is working for backward compatibility
    BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
    pAdvertising->addServiceUUID(SERVICE_UUID);
    pAdvertising->setScanResponse(true);
    pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
    pAdvertising->setMinPreferred(0x12);
    pServer->getAdvertising()->start();
}