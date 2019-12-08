#include<iostream>
using namespace std;
int main() {
	double f = 1;
	double n;
	cout << "Enter a number\n";
	cin >> n;

	int i = 1;
	do {
		f *= i;
		i++;
	} while (i <= n);

	cout << n << "! = " << f;

}
