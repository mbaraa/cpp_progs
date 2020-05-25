#include <stdio.h>
// test functions
void *f1(){
    printf("f1 blyat\n");
}
void *f2(){
    printf("f2 blyat\n");
}
// hmm
// funcPtr is a pointer to function(not specified) in normal cases
// here "funcPtr" is a new type i.e. the function pointer
typedef void (*funcPtr)(void); // for future uses we can change number of parameters(or add in this case :))
                        // and the return type
/* templates:
    int (*funcPtr)(void);
    int (*funcPtr)(int,int);
    double (*funcPtr)(void);
    char (*funcPtr)(void);
    char (*funcPtr)(char);
    char* (*funcPtr)(char,int);
    and so on ....
*/
// using the type as a return type in a function
funcPtr hmm(){
    printf("hmm\n");
}

int main(void){
    // function pointer(or pointer to function)
    void (*someName)(void) = &hmm;
    // invoking hmm() using "someName"
    someName();
    
    // declaring array of functions from the function pointer type :)
    funcPtr arrayOfFunctions[3] = {&f1, &f2};

    // invoking each function by its index 
    arrayOfFunctions[0](); 
    arrayOfFunctions[1](); 
      
    return 0;
}
