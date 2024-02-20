#include "Message.h"

#ifndef VALUE_MESSAGE
#define VALUE_MESSAGE

template<typename T> class ValueMessage : public Message {
    public: 
        ValueMessage(T value);
        T getValue();

    private:
        T m_value;
    
};

template<typename T> ValueMessage<T>::ValueMessage(T value){
    this->m_value = value;
}

template<typename T> T ValueMessage<T>::getValue(){
    return this->m_value;
}

#endif