#include <cstdio>

int main(){
    int i = 0;
    
    some_label:
        printf("Hmm\n");
        i++;
        if(i < 10)
            goto some_label;
        
    return 0;
}
