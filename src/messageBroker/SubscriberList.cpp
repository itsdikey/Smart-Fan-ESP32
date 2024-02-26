#include "SubscriberList.h"

SubscriberListItem::SubscriberListItem(){
    value = nullptr;
    next = nullptr;
}


SubscriberListIterator::SubscriberListIterator(SubscriberListItem* start){
    current = start;
}

bool SubscriberListIterator::hasMore(){
    return current == nullptr;
}

SubscriberListItem* SubscriberListIterator::getNext(){
    if(current == nullptr){
        return nullptr;
    }

    SubscriberListItem* copyOfCurrent = current;
    current = current->next;

    return copyOfCurrent;
}

int SubscriberList::getCount(){
    return count;
}

MessageSubscriber* SubscriberList::getAt(int index){
    int x = 0;
    SubscriberListItem* current = head;

    while(x<index){
        current = current->next;
        x++;
    }
    return current->value;
}

void SubscriberList::addBack(MessageSubscriber& messageSubscriber){
    if(count==0){
        head = new SubscriberListItem();
        head->value = &messageSubscriber;
        last = head;
    }
    else{
        SubscriberListItem* newItem = new SubscriberListItem();
        newItem->value = &messageSubscriber;
        last->next = newItem;
        last = newItem;
        // SubscriberListItem* current = head;
        // while(current->next!=nullptr){
        //     current = current->next;
        // }
        // current->next = newItem;
        // last = current;
    }
    count++;
}

SubscriberListIterator* SubscriberList::iterator(){
    return new SubscriberListIterator(head);
}