#include<iostream>
using namespace std;
int main(){
	int f=1,n;
	cout << "Enter a number\n";
	cin >> n;
	for(int i = 1;i<=n;i++){
		f *= i;
		}
	cout << n << "! = " << f;

}
