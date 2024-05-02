#include "BLENotifySystem.h"
#include "messages/Topics.h"

BLENotifySystem::BLENotifySystem(
    MessageQueueInt *messageQueue, 
    FanBLEServer *bleServer, 
    DeviceState *deviceState)
{
    this->m_messageQueue = messageQueue;
    this->m_bleServer = bleServer;
    this->m_deviceState = deviceState;
}
void BLENotifySystem::loop()
{
    if (!m_messageQueue->hasMessage())
        return;
    switch (m_messageQueue->getCurrentMessage()->getTopic())
    {
        case TopicButtonPressed:
            if (m_deviceState->getSpeed() == Speed0)
            {
                m_bleServer->setSpeedValue(0);
            }
            if (m_deviceState->getSpeed() == Speed1)
            {
                m_bleServer->setSpeedValue(1);
            }
            if (m_deviceState->getSpeed() == Speed2)
            {
                m_bleServer->setSpeedValue(2);
            }
            if (m_deviceState->getSpeed() == Speed3)
            {
                m_bleServer->setSpeedValue(3);
            }

            break;

        default:
            break;
    }
}