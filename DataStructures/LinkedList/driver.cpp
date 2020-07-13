#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// driver
int main() {

    LinkedList<int> *ll = new LinkedList<int>(9);
    ll->addElement(8);
    //ll->addElement(7);

    int hoo = ll->getHead()->getValue();
    int moo = ll->getHead()->getNext()->getValue();
    int foo;// = ll->getHead()->getNext()->getNext()->getValue(); 
    printf("head: %d \nnext to head: %d\nanother fucker: %d", hoo, moo, foo);

    
   /* Node<int> *loo = ll->getHead()->getNext();

    printf("%d\n",loo->getValue());
*/
    //printf("element 1: prev: %d, curr: %d, next: %d", loo->getValue(), loo->getNext()->getValue(), loo->getPrev()->getValue() );

    

    return 0;
}