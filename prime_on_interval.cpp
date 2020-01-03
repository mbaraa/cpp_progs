#include<iostream>
using namespace std;
int IsPrime(int x);
int main(){
	int a,b;
	cout << "Input an interval [a,b] in this form" << endl;
	cin >> a >> b;
	cout << "Prime numbers in this interval are ";
	for(int n = a ; n <= b;n++){
		
		if(!IsPrime(n)){
			continue;
		}
		else if(IsPrime(n)){
			cout << n << " ";
		}
	}
	cout << endl;
	return 0;
}

int IsPrime(int x){

	bool prime = 1;
	for(int n = 2 ; n <= x/2 ; n++){
		if(x % n == 0){
			prime = 0;
			break;
		}
	}
	return prime;
}
