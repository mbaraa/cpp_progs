#include <stdlib.h>
#include <stdio.h>
// for typo
#define temp template<typename type>

temp
class StackMimic{
public:
    
    StackMimic(int size);
    StackMimic();
    bool isEmpty();
    bool isFull();
    void push(type element);
    type show();
    void pop();

private:

    int size;
    type *stackElements = (type*)malloc(sizeof(type)*size);
    int topIndex = -1;

    bool checkCapacity();

};

// rest of the thing
temp
StackMimic<type>::StackMimic(int size){
    this->size = size;
}
temp
StackMimic<type>::StackMimic() : StackMimic(0){

}

temp
bool StackMimic<type>::isFull(){
    return this->topIndex == (size - 1);
}

temp
bool StackMimic<type>::isEmpty(){
    return this->topIndex == -1;
}

temp
bool StackMimic<type>::checkCapacity(){
    return !isEmpty() && !isFull();
}

temp
void StackMimic<type>::push(type e){
    if(!isFull()){
        this->topIndex -=- 1;
        this->stackElements[this->topIndex] = e; 
    }
}

temp
void StackMimic<type>::pop(){
    if(!isEmpty()){
        this->topIndex -= 1;
    }
}

temp
type StackMimic<type>::show(){
    if(!isEmpty()){
        return this->stackElements[this->topIndex];
    }
}

//driver
int main(){
    StackMimic<int> *stk = new StackMimic<int>(5);

    stk->push(2);
    stk->push(4);
    stk->push(69);
    stk->push(244);
    stk->push(420);

    for (int lol = 0; lol < 5; lol++ ){
        printf("element %d: %d\n", lol+1, stk->show());
        stk->pop();
    }
    
    return 0;
}
