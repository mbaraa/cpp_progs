#include <stdio.h>
#include <stdlib.h>

#define TEMP template<typename type>

// Node.h
TEMP
class Node {
public:
    // constructors
    Node(type);
    Node();
    // set next element pointer
    void setNext(Node *);
    // get next element object
    Node *getNext();
    // set previous element pointer
    void setPrev(Node *);
    // get previous element object
    Node *getPrev();
    // set node's value
    void setValue(type);
    // get node's value
    type getValue();

private:
    // next element object
    Node *next;
    // prevoius element object
    Node *prev;
    // current node value
    type value;

};

// Node.cpp
TEMP
// constructor
Node<type>::Node(type value) {
    this->value = value;
}
TEMP
Node<type>::Node() {
    
}


TEMP
// set node's value
void Node<type>::setValue(type value) {
    this->value = value;
}

TEMP
// get next's object
Node<type> *Node<type>::getNext() {
    return this->next;
}
TEMP

// set next's pointer
void Node<type>::setNext(Node *nextValue) {
    this->next = nextValue;
}

TEMP
// get previous' object
Node<type> *Node<type>::getPrev() {
    return this->prev;
}
TEMP

// set prevouis' pointer
void Node<type>::setPrev(Node *prevValue) {
    this->prev = prevValue;
}

TEMP
// get node's value
type Node<type>::getValue() {
    return this->value;
}
