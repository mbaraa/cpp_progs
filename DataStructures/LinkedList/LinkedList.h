#ifndef LINKDEDLIST_H
#define LINKDEDLIST_H

#include <stdlib.h>
#include "Node.h"

#define TEMP template<typename type>

TEMP
class LinkedList {
public:
    // constructors
    LinkedList(type);
    LinkedList();
    // add new element
    void addElement(type);
    // delete an element
    void deleteElement(type);
    // find element with given key
    Node<type> *findElement(type);
    // check if element is found or not
    bool isElementFound(type);
    // get head's value
    Node<type> *getHead();
    // set head's node
    void setHead(Node<type> *);
    // get tail's value
    Node<type> *getTail();
    // search the linked list
    

private:
    // head's value
    Node<type> *head;
    // tail's value
    Node<type> *tail;

    // go to tail
    Node<type> *goToTail();

};

TEMP
// constructors
LinkedList<type>::LinkedList(type head) {
    this->head = new Node<type>(head);
    this->head->setPrev(NULL);
}
TEMP
LinkedList<type>::LinkedList(): LinkedList(0) {
}

TEMP
// go to tail
Node<type> *LinkedList<type>::goToTail() {
    Node<type> *tmp = new Node<type>;
    tmp = this->head;
    while( tmp->getNext() != nullptr ) {
        tmp = tmp->getNext();
    }
    return tmp;
}

TEMP
// add a new element to the linked list
// note that elements are added to linked list at head
void LinkedList<type>::addElement(type element) {
    // taking values from the current head
    Node<type> *tmp = new Node<type>( this->head->getValue() );    
    tmp->setNext( this->head->getNext() );
    // the new head
    Node<type> *newHead = new Node<type>(element);
    // add the new head before the current head
    tmp->setPrev(  newHead );
    // add the current head after the new head
    newHead->setNext( tmp );
    // set new head's previous to null
    newHead->setPrev( nullptr );
    // update the head
    this->head = newHead;

    // update tail
    this->tail = this->goToTail();
}

TEMP
// delete an element
void LinkedList<type>::deleteElement(type key) {
    this->findElement( key )->setPrev( this->findElement( key )->getNext() );
    Node<type> *tmp = this->head;
    while(tmp->getValue() != key) {
        
    }

}

TEMP
// find element with given key
Node<type> *LinkedList<type>::findElement(type key) {
    
    Node<type> *tmp = new Node<type>;
    // start with head
    tmp = this->head;
    // go through the elements until element is found or reached end of LL
    while ( tmp->getValue() != key && tmp->getNext() != nullptr ) {
        tmp = tmp->getNext();
    }
    // returns the found element, if not found return the tail
    return tmp; 

}

TEMP
// check whether the element if found in the linked list
bool LinkedList<type>::isElementFound(type key) {
    Node<type> *tmp = new Node<type>;
    // start with head
    tmp = this->head;
    // go through the elements until element is found or reached end of LL
    while ( tmp->getValue() != key && tmp->getNext() != nullptr ) {
        tmp = tmp->getNext();
    }
    // returns true if a matching element is found
    return ( tmp->getValue() == key ); 
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

TEMP
// set head's node
void LinkedList<type>::setHead(Node<type> *newHead) {
    this->head = newHead;
}
#endif // LINKEDLIST_H