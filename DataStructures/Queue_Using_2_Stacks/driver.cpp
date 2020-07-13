#include <stdio.h>
#include "qu2s.h"

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
