#include<iostream>
using namespace std;
double larger(double a, double b); 
int fact(int x);
void eee(int x);
void printstars();

int main() {
	printstars();

	double x, y;
	cout << "Input two number to compare:\n";
	cin >> x >> y; 
	cout << "\nMax = " << larger(x,y) << endl;
	x = 0, y = 0;

	cout << "Input a number to find its factorial :\n";
	cin >> x;
	cout << fact(x) << endl;

	cout << "Input a number to find even integers from 1 to the number :\n";
	cin >> x;
	eee(x);
	printstars();

	return 0;
}

double larger(double a, double b) {
	if (a > b)
		return a;
	else
		return b;
}
int fact(int x) {
	int fact = 1;
	for (int i = 1; i <= x; i++) {
		fact *= i;
	}
	return fact;
}
void eee(int x) {
	for (int i = 2; i <= x; i++) {
		if (i % 2 == 0) {
			cout << i << " " << endl;
		}
	}
}
void printstars() {
	cout << "*****\n";
}
