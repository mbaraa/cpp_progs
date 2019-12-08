#include<iostream>
#include<string>
using namespace std;
int main (){
	cout << "Enter a number:\n";
	int no;\
	string state;
	cin >> no ;
		if(no == 2 || no == 3 || no == 5 || no == 7 ){
			state = ("Prime!");
			}

		else if(no%2==0 || no%3==0 || no%5==0 || no%7==0 ){
			state = ("Not Prime!");
			}
		else {
			state = ("Prime!");
			}
		
		cout << state << endl;
	
	return 0 ;

}
		


				
	
