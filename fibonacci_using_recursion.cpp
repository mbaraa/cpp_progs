//recursion example!
//finally I made the damn fibonacci
#include<iostream>
using namespace std;
int fibonacci(int number);
int main(){
    cout << "Program is Terminated by E.O.F!\n\n";
    while(true){
        cout << "Enter a number: ";
        int number;
        cin >> number;
        cout << fibonacci(number) << endl;
    }

    return 0;
}
int fibonacci(int number){
    if(number == 1 || number == 0)
        return number;
    else
        return fibonacci(number-1) + fibonacci(number-2);
}
