#include<iostream>
using namespace std;
int main(){
	double f=1;
	int n;
	cout << "Enter a number\n";
	cin >> n;
	for(int i = 1;i<=n;i++){
		f *= i;
		}
	cout << n << "! = " << f;

}
