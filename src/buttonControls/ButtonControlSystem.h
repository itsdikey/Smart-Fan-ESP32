#include <messages/MessageQueueInt.h>
#include <messages/Topics.h>
#include <ezButton.h>

#ifndef BUTTON_CONTROLS
#define BUTTON_CONTROLS


class ButtonControlSystem{
    public:
    ButtonControlSystem(MessageQueueInt* messageQueueInt);
    void loop();

    private:
    MessageQueueInt* m_messageQueueInt;
    ezButton speed_1Button = ezButton(1);
    ezButton speed_2Button = ezButton(2);
    ezButton speed_3Button = ezButton(3);
};  


#endif