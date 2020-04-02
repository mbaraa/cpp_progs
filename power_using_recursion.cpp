//recursion example!
#include<iostream>
using namespace std;
int power(int base,int exponent);
int main(){
    cout << "Program is Terminated by E.O.F!\n\n";
    while(true){
        cout << "Enter number and desiered power: ";
        int number,exp;
        cin >> number >> exp;
        cout << power(number,exp) << endl;
    }

    return 0;
}
int power(int base, int exponent){
    static int out = 1;
    out *= base;
    if(exponent == 1){
        int temp = out;
        out = 1;
        return temp;
    }
    else
        return power(base,exponent-1);
}
//more elegent way I found on SOF
/*
int power(int base, int exponent){
    if (exponent==1)
        return base;
    else
        return base * power(base, exponent - 1);
}
*/
