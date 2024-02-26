#include "messages/MessageSubscriber.h"

#ifndef SUBSCRIBER_LIST_HEADER
#define SUBSCRIBER_LIST_HEADER

class SubscriberListItem{
    public :
    MessageSubscriber* value;
    SubscriberListItem* next;
    SubscriberListItem();
};

class SubscriberListIterator{
    public:
        SubscriberListIterator(SubscriberListItem* start);
        bool hasMore();
        SubscriberListItem* getNext();

    private:
        SubscriberListItem* current;
};






class SubscriberList{
    public:
    SubscriberList(){
        count = 0;
        head = nullptr;
        last = nullptr;
    }
    int getCount();
    void addBack(MessageSubscriber& messageSubscriber);
    MessageSubscriber* getAt(int index);
    SubscriberListIterator* iterator();
    private:
    SubscriberListItem* head;
    SubscriberListItem* last;
    int count;
};

#endif