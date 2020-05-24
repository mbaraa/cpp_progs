#include <cstdio>
class moo{
public:
    int i=0;
    // pointer function, well because objects are stored on the heap
    // and you know "this" is a pointer so ....
    moo *increment(){
        i++;
        return this;
    }
};
int main(){
    // creating an instance object
    moo *k = new moo();
    // calling the function "increment()" more than once
    // well because this function returns object of type moo so
    // it can access that object's functions and variables
    k->increment()->increment()->increment()->increment();
    printf("value of \"i\" modified by increasing 1 each function call: \ni = %d\n", k->i);
    // accessing the variable "i" from the returned object from "increment()" function
    k->increment()->i = 2;
    printf("value modified of \"i\" explicitly assigned to 2: \ni = %d\n", k->i);

    return 0;
}
