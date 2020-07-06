#include <stdio.h>
#include <stdlib.h>
#include <stack>
// template macro
#define temp template<typename type>

temp
class QueueUsingStacks{
public:
    QueueUsingStacks(int size);
    void enqueue(type element);
    type dequeue();
    bool isEmpty();// if stack1 is empty
    bool isFull(); // not applicable

private:
    int size;   
    std::stack<type> *stk1;
    std::stack<type> *stk2;
    
};

temp
// constructor
QueueUsingStacks<type>::QueueUsingStacks(int size){
    this->size = size;

    stk1 = new std::stack<type>;
    stk2 = new std::stack<type>;
}

temp
// enqueue(push) the queue i.e. insert element at the tail
void QueueUsingStacks<type>::enqueue(type element){
    this->stk1->push(element);
}

temp
// dequeue(pop) the queue i.e. return the value at the head
type QueueUsingStacks<type>::dequeue(){
    // pushing stack1 to stack2
    while(!this->stk1->empty()){
        this->stk2->push(stk1->top());
        this->stk1->pop();
    }
    // temporary variable to store the top variable of stack2
    type top;
    top = stk2->top();
    // rempving top element from stack2
    stk2->pop();
    // readding stack2 to stack1
    while(!this->stk2->empty()){
        this->stk1->push(stk2->top());
        this->stk2->pop();
    }
    // return the top value of stack2
    return top;
}

// driver
int main(){
    QueueUsingStacks<char> *queue = new QueueUsingStacks<char>(4);

    for(int k = 0; k < 4; k++){
        queue->enqueue(k + 65);
    }
     
    for(int k = 0; k < 4; k++){
        printf("element %d: %c\n",k+1 ,queue->dequeue());
    }

    return 0;
}
