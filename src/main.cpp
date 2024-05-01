#include "deviceState/DeviceState.h"
#include "messages/MessageQueueInt.h"
#include "bleService/BLEServer.h"
#include "systems/DeviceControlSystem.h"
#include "systems/BLENotifySystem.h"
#include "systems/DisplaySystem.h"
#include "messages/Topics.h"
#include <Arduino.h>

MessageQueueInt* messageQueueInt;
DeviceControlSystem *deviceControlSystem ;
BLENotifySystem* bleNotifySystem;
DisplaySystem* displaySystem;


void setup() {
  Serial.begin(115200);
  messageQueueInt = new MessageQueueInt();

  
  DeviceState *deviceState = new DeviceState(messageQueueInt);
  FanBLEServer *fanBleServer = new FanBLEServer(messageQueueInt);
  deviceControlSystem = new DeviceControlSystem(messageQueueInt, deviceState);
  bleNotifySystem = new BLENotifySystem(messageQueueInt, fanBleServer);
  displaySystem = new DisplaySystem(messageQueueInt);
}

void loop() {
    
    deviceControlSystem->loop();
    bleNotifySystem->loop();
    displaySystem->loop();
    messageQueueInt->popLast();
}
