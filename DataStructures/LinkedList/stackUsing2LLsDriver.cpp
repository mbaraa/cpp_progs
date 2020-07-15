// stack using a doubly linked list
#include "LinkedList.h"
// note that the macro TEMP is declared in LinkedList.h

TEMP
class StackUsingLL {
public:
    StackUsingLL(type);
    void push(type);
    type pop();
private:    
    LinkedList<type> *stackElements;
    
};


TEMP
// constructor 
StackUsingLL<type>::StackUsingLL(type firstElement) {
    
    stackElements = new LinkedList<type>(firstElement);
}

TEMP
// pop element on top
type StackUsingLL<type>::pop() {
    Node<type> *tmp = this->stackElements->getHead();
    // remove cuurent head by setting its value to the element after it
    this->stackElements->setHead( stackElements->getHead()->getNext() );

    return tmp->getValue();
}

TEMP
// add an element to the stack
void StackUsingLL<type>::push(type element) {
    Node<type> *tmp = new Node<type>(element);
    // set current head as next of the new head
    tmp->setNext( this->stackElements->getHead() );
    // set the new head as the previous of the current head
    this->stackElements->getHead()->setPrev(tmp);
    // finally set new head as head
    this->stackElements->setHead(tmp);
}

// driver
#include <stdio.h>

int main() {
    StackUsingLL<char> *sll = new StackUsingLL<char>(97);
    
    sll->push(98);
    sll->push(99);
    sll->pop();
    sll->pop();

    printf("\n%c\n", sll->pop());   

    return 0;
}

