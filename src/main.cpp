#include "deviceState/DeviceState.h"
#include "messageBroker/MessageBroker.h"
#include "bleService/BLEServer.h"
#include <Arduino.h>

// See the following for generating UUIDs:
// https://www.uuidgenerator.net/

//#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
//#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

void setup() {
  Serial.begin(115200);
  MessageBroker *messageBroker = new MessageBroker();
  DeviceState *deviceState = new DeviceState(messageBroker);
  FanBLEServer *fanBleServer = new FanBLEServer(messageBroker);
}

void loop() {
}
