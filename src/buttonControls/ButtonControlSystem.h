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
    ezButton* speedButton = new ezButton(3);
    bool canCheck;
};  


#endif