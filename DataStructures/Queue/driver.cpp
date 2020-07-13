#include <stdio.h>
#include "Queue.h"
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
