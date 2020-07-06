#include <stdio.h>
#include <stdlib.h>
// template macro
#define temp template<typename type>

temp
class QueueMimic{
public:
    QueueMimic(int);
    void enqueue(type);
    type dequeue();
    int topIndex;
    bool isFull();
    bool isEmpty();
    void copy(QueueMimic*);

private:
    type *queueElements;
    int queueSize;
    int tailIndex;
    int headIndex;
    int size;
};

temp
// constructor 
QueueMimic<type>::QueueMimic(int size){
    this->size = size;
    tailIndex = -1;
    headIndex = 0;
    //queueElements = new type[queueSize];
    queueElements = (type*)malloc(sizeof(type)*queueSize);
}

temp
// push new element to the tail of the stack
void QueueMimic<type>::enqueue(type element){
    // post increament of the tail index while adding the new element
    queueElements[++tailIndex] = element;
}

temp
// remove element from the head of the stack
type QueueMimic<type>::dequeue(){
    // temp variable to hold the value of the head of the queue
    type head;
    head = this->queueElements[headIndex];
    // shifting queue's elements one step back
    for(int k = 0; k < this->tailIndex ; k++){
        this->queueElements[k] = this->queueElements[k+1];
    }
    // decrease the tail index
    this->tailIndex--;
    // return the value of the head before shifting     
    return head;
}

temp
// returns true is the queue is empty
bool QueueMimic<type>::isEmpty(){
    return this->headIndex == 0 && this->tailIndex == -1;
}

temp
// returns true is the queue is full
bool QueueMimic<type>::isFull(){
    return this->tailIndex == this->size - 1;
}

// driver
int main(){
    QueueMimic<char> *queue = new QueueMimic<char>(4);

    printf("isEmpty : %d\n", queue->isEmpty());
    printf("isFull : %d\n\n", queue->isFull());

    for(int k = 0; k < 4; k++){
        queue->enqueue(k + 65);
    }
    
    printf("\nisEmpty : %d\n", queue->isEmpty());
    printf("isFull : %d\n\n", queue->isFull());
    
    for(int k = 0; k < 4; k++){
        printf("element %d: %c\n",k+1 ,queue->dequeue());
    }

    printf("\nisEmpty : %d\n", queue->isEmpty());
    printf("isFull : %d\n\n", queue->isFull());
    return 0;
}
