#include "deviceState/DeviceState.h"
#include "messages/MessageQueueInt.h"
#include "bleService/BLEServer.h"
#include "systems/DeviceControlSystem.h"
#include "messages/Topics.h"
#include <Arduino.h>

MessageQueueInt* messageQueueInt;
DeviceControlSystem *deviceControlSystem ;


void setup() {
  Serial.begin(115200);
  messageQueueInt = new MessageQueueInt();

  
  DeviceState *deviceState = new DeviceState(messageQueueInt);
  FanBLEServer *fanBleServer = new FanBLEServer(messageQueueInt);
  deviceControlSystem = new DeviceControlSystem(messageQueueInt, deviceState);
}

void loop() {
    deviceControlSystem->loop();
    messageQueueInt->popLast();
}
