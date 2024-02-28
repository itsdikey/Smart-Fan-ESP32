#include "BLENotifySystem.h"
#include "messages/Topics.h"

BLENotifySystem::BLENotifySystem(MessageQueueInt* messageQueue, FanBLEServer* bleServer){
    this->m_messageQueue = messageQueue;
    this->m_bleServer = bleServer;
}
void BLENotifySystem::loop(){
     if(!m_messageQueue->hasMessage())
        return;
    switch (m_messageQueue->getCurrentMessage()->getTopic())
    {
        case TopicBLEChange:
            m_bleServer->setSpeedValue(m_messageQueue->getCurrentMessage()->getValue());
        break;
        
        default:
            break;
    }
}