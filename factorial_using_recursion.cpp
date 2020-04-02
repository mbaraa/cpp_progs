//recursion example!
#include<iostream>
using namespace std;
int factorial(int number);
int main(){
    cout << "Program is Terminated by E.O.F!\n\n";
    while(true){
        cout << "Enter a number: ";
        int number;
        cin >> number;
        cout << factorial(number) << endl;
    }

    return 0;
}
int factorial(int number){
    if(number <= 1)
        return 1;
    else
        return number * factorial(number-1);
}
