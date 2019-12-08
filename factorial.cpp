#include<iostream>
using namespace std;
int main() {
	double n;
	cout << "Input a number :\n";
	cin >> n;
	double r = n;
	double  k = n - 1;
	if (n==1 || n==0){
		cout << n << "! = "<< "1" <<endl;
		}
	else { 
		for (int f = n ; f > 1 ; f--){
			n = n * k;
			k--;
		}
		cout << r <<"! = "<< n << endl;
		
		}
	return 0;
}
			
	
