#include "DisplaySystem.h"
#include "messages/MessageSubscriber.h"
#include "Arduino.h"
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>

U8G2_SSD1306_64X32_NONAME_1_4W_HW_SPI display(U8G2_R0, 7 ,6);

DisplaySystem::DisplaySystem(MessageQueueInt* messageQueueInt){
    this->m_messageQueueInt = messageQueueInt;
    display.begin();
}

void DisplaySystem::loop(){
  display.clearBuffer();
  display.setFont(u8g2_font_ncenB14_tr);
  display.drawStr(0,20,"Hello World!");
  display.sendBuffer();
}


