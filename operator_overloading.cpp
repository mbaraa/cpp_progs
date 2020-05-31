#include <iostream>
#include <math.h>
using namespace std;
class A{
public:
    A(int x){
        this->x = x;
    }
    // add a primitive to a pirimitive variable
    A operator += (int k){
        this->x += k;
        // return the updated value of the object
        return *this;
    }
    
    // add a primitive from object to a pirimitive variable
    A operator += (A k){
        this->x += k.x;
        // return the updated value of the object
        return *this;
    }

    int x = 9;

};

int main(){
    
    A *a = new A(9);

    printf("old x in a %d\n", a->x);
    *a += 40;
    printf("new x in a %d\n", a->x);
    

    A *b = new A(3);
    printf("old value of x in b %d\n", b->x);
    *b += *a;
    printf("new value of x in b %d\n", b->x);
    

    return 0;
}
