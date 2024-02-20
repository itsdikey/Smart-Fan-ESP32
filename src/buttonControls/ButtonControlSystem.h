#include <messageBroker/MessageBroker.h>
#include <messages/Topics.h>
#include <messages/ValueMessage.h>
#include <ezButton.h>

#ifndef BUTTON_CONTROLS
#define BUTTON_CONTROLS


class ButtonControlSystem{
    public:
    ButtonControlSystem(MessageBroker* messageBroker);
    void loop();

    private:
    MessageBroker* m_messageBroker;
    ezButton speed_1Button = ezButton(1);
    ezButton speed_2Button = ezButton(2);
    ezButton speed_3Button = ezButton(3);
};  


#endif