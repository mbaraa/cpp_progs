#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

#define TEMP template<typename type>

TEMP
class LinkedList {
public:
    // constructor
    LinkedList(type);
    // add new element
    void addElement(type);
    // get head's value
    Node<type> *getHead();    
    // get tail's value
    Node<type> *getTail();
    // search the linked list
    

private:
    // head's value
    Node<type> *head;
    // tail's value
    Node<type> *tail;

};

TEMP
// constructor
LinkedList<type>::LinkedList(type head) {
    this->head = new Node<type>(head);
    this->head->setPrev(NULL);
}

TEMP
// add a new element to the linked list
void LinkedList<type>::addElement(type element) {
    Node<type> *newHead = new Node<type>(element);

    Node<type> *tmp = new Node<type>( this->head->getValue() );    
    
    newHead->setNext( tmp );

    newHead->setPrev( NULL );

    this->head = newHead;

    /*
    // set new element as the new head
    newHead->setNext(this->head);
    // check whether if the list is empty
    if( this->head != NULL) {
        this->head->setPrev(newHead);        
    }
    // update head's value
    //this->head->setValue( newHead->getValue() );
    
    head = newHead;
    // ensure that head.prev = NULL
    head->setPrev(NULL);

    delete newHead;
    // update tail's value
    //this->tail->setPrev();
    */
}

TEMP
// get head's value
Node<type> *LinkedList<type>::getHead() {
    return head;
}

TEMP
// get tail's value
Node<type> *LinkedList<type>::getTail() {
    return tail;
}