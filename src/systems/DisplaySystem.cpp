#include "DisplaySystem.h"
#include "messages/MessageSubscriber.h"
#include "Arduino.h"
#include <U8g2lib.h>
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
#include <U8x8lib.h>

U8X8_SSD1306_64X32_1F_HW_I2C u8x8(/* reset=*/U8X8_PIN_NONE, 7, 6);
DisplaySystem::DisplaySystem(DeviceState *deviceState)
{
    this->m_deviceState = deviceState;
    u8x8.begin();
    this->lastChange = millis();
    this->m_lastSpeed = deviceState->getSpeed();
}

void DisplaySystem::loop()
{

    u8x8.setFont(u8x8_font_courB24_3x4_n);

    switch (this->m_deviceState->getSpeed())
    {
        case Speed0:
            u8x8.drawString(64, 0, " 0");
            break;
        case Speed1:
            u8x8.drawString(64, 0, " 1");
            break;
        case Speed2:
            u8x8.drawString(64, 0, " 2");
            break;
        case Speed3:
            u8x8.drawString(64, 0, " 3");
            break;
    }

    if (this->m_deviceState->getSpeed() != this->m_lastSpeed)
    {
        this->lastChange = millis();
        u8x8.setPowerSave(false);
    }

    if (millis() - this->lastChange > this->maxChange)
    {
        u8x8.setPowerSave(true);
    }
}