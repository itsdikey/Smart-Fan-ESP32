#include "DeviceControlSystem.h"
#include "messages/MessageSubscriber.h"
#include "Arduino.h"


#include <ezBuzzer.h> // ezBuzzer library


const int BUZZER_PIN = 23;


ezBuzzer buzzer(BUZZER_PIN); // create ezBuzzer object that attach to a pin;

// notes in the melody:
int melody[] = {
  NOTE_F5, NOTE_A5, NOTE_C5
};

// notes in the melody:
int melody2[] = {
  NOTE_C6, NOTE_A5, NOTE_F5
};

// note durations: 4 = quarter note, 8 = eighth note, etc, also called tempo:
int noteDurations[] = {
  2, 2, 2
};


DeviceControlSystem::DeviceControlSystem(MessageQueueInt* messageQueueInt, DeviceState* deviceState){

    
    this->m_messageQueueInt = messageQueueInt;
    this->deviceState = deviceState;

    Serial.println("Pre Subscribe");
    //messageBroker->subscribe(TopicBLEChange, deviceControlSystemSubscriber);
    // messageBroker->subscribe(TopicButtonPressed, *deviceControlSystemSubscriber);
}

void DeviceControlSystem::loop(){
    buzzer.loop();
    int value;
    if(!m_messageQueueInt->hasMessage())
        return;
    switch (m_messageQueueInt->getCurrentMessage()->getTopic())
    {
        case TopicBLEChange:
            Serial.println("TopicBLEChange changed");
            value = m_messageQueueInt->getCurrentMessage()->getValue();
            Serial.println(value);
            //deviceState->setSpeed((FanSpeed)value);
            if(value==1){
               buzzer.playMelody(melody, noteDurations,1);
            }
            if(value==2){
                  buzzer.playMelody(melody, noteDurations,2);
            }

            if(value==3){
                 buzzer.playMelody(melody, noteDurations,3);
            }

            if(value==0){
                buzzer.playMelody(melody2, noteDurations,3);
            }
            break;

        case TopicButtonPressed:
            Serial.println("TopicButtonPressed changed");
        break;
        
        default:
            break;
        }
}


