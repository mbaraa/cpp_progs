#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
// for typo
#define temp template<typename type>

temp
class StackMimic{
public:
    // constructors & destructor
    StackMimic(int size);
    StackMimic();
    ~StackMimic();

    bool isEmpty();
    bool isFull();
    void push(type element);
    type pop();
    type show();

private:

    int size;
    type *stackElements;
    int topIndex = -1;
    
    bool checkCapacity();

};

// rest of the thing

temp
// constructors
StackMimic<type>::StackMimic(int size){
    this->size = size;
    this->stackElements = (type*)malloc(sizeof(type)*size);
}
temp
StackMimic<type>::StackMimic() : StackMimic(0){

}

temp
StackMimic<type>::~StackMimic() {
    free(stackElements);
}

temp
// returns true if the stack is full
bool StackMimic<type>::isFull(){
    return this->topIndex == (size - 1);
}

temp
// returns true if the stack is empty
bool StackMimic<type>::isEmpty(){
    return this->topIndex == -1;
}

temp
// returns true is the stack is niether empty nor full
bool StackMimic<type>::checkCapacity(){
    return !isEmpty() && !isFull();
}

temp
// insert a new element to the stack
void StackMimic<type>::push(type e){
    if(!isFull()){
        this->topIndex++;
        this->stackElements[this->topIndex] = e; 
    }
}

temp
// delete and return the top element of the stack
type StackMimic<type>::pop(){
    if(!isEmpty()){
        this->topIndex--;
        return stackElements[topIndex+1];
    }
}

temp
// pop w/o deletion
type StackMimic<type>::show(){
    if(!isEmpty()){
        return stackElements[topIndex];
    }
}

#endif