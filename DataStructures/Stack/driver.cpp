#include <stdlib.h>
#include "Stack.h"
//driver
int main(){
    StackMimic<int> *stk = new StackMimic<int>(5);

    stk->push(2);
    stk->push(4);
    stk->push(69);
    stk->push(244);
    stk->push(420);

    for (int lol = 0; lol < 5; lol++ ){
        printf("element %d: %d\n", lol+1, stk->pop());        
    }
    
    return 0;
}
