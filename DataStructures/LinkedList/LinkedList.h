#ifndef LINKDEDLIST_H
#define LINKDEDLIST_H

#include <stdlib.h>
#include "Node.h"
#include <vector>

#define TEMP template<typename type>

TEMP
class LinkedList {
public:
    // constructors
    LinkedList(type);
    LinkedList();
    // destructor
    ~LinkedList();
    // add new element
    void addElement(type);
    // delete an element
    void deleteElement(type);
    // find element with given key
    int findElement(type);
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
    
    // elements counter
    int counter;
    // go to tail
    Node<type> *goToTail();

    // lookup table
    std::vector< Node<type> * > *indexs;

};

TEMP
// constructors
LinkedList<type>::LinkedList(type head) {
    // initalize head
    this->head = new Node<type>(head);
    this->head->setPrev(NULL);
    // initalize counter
    this->counter = 1; // starts with one because of the first element
    // initalize index table
    this->indexs = new std::vector< Node<type> * >;
    // add head to index table
    this->indexs->push_back(this->head);

}   
TEMP
LinkedList<type>::LinkedList(): LinkedList(0) {
}
/*
TEMP
// destructor
LinkedList<type>::~LinkedList() {
    delete indexs;
    delete head;
    delete tail;
}
*/
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
    // update counter
    this->counter++;
    // update lookUp table
    this->indexs->push_back(this->head);
}

TEMP
// delete an element // BROKEN!!
void LinkedList<type>::deleteElement(type key) {
    
    int index = this->findElement(key);

    if(index > -1) {    
        this->indexs->at(key)->getPrev();
    }
}

TEMP
// find element with given key
int LinkedList<type>::findElement(type key) {
    
    for(int kounter = 0; kounter < this->counter; kounter++) {
        if( this->indexs->at(this->counter - 1 - kounter)->getValue() == key ) {
            return kounter;
        }
    }
    
    // if element is not found return -1
    return -1;

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