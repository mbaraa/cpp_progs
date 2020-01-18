#include<iostream>
using namespace std;
int main (){
	cout << "Enter a number:\n";
	int no;
	bool prime = 1;
	string state;
	cin >> no ;
	for(int i = 2 ; i <= no / 2 ; i++){
		if(no % i == 0){
			prime = 0;
			break;
			}
		}
	if(prime)
		cout << "Prime!\n";
	else 
		cout << "Not Prime!\n";
	return 0 ;

}
