#include <iostream>
#include <math.h>
#include <string>
using namespace std;
int main(int) {
	double x, y;
	char op;
	cout << "\nEnter Two Numbers (x,y):\n";
	cin >> x >> y;
	cout << "\nChoose an Operation:\n "
		 << "----------------------\n"
		<< "1.Addition\n"
		<< "2.Subtraction\n"
		<< "3.Multiplection\n"
		<< "4.Division\n"
		<< "5.Power x^y \n"
		<< "6.Square Root of x\n"
		<< "7.Normal Logarithm of x\n"
		<< "8.Exit\n";
	cin >> op;
	switch (op) {
	case '1':
		cout << x << "+" << y << "="
			<< x + y << endl;
		break;

	case '2':
		cout << x << "-" << y << "="
			<< x - y << endl;
		break;

	case '3':
		cout << x << "*" << y << "="
			<< x * y << endl;
		break;
	case '4':
		if (y != 0) {
			cout << x << "/" << y << "="
				<< x / y << endl;
		}
		else {
			cout << "can't divide by 0";
		}
		break;
	case '5':
		cout << x << "^" << y << "="
			<< pow(x, y) << endl;
		break;
	case '6':
		cout << "sqrt of" << x << "="
			<< sqrt(x) << endl;
		break;
	case '7':
		cout << "ln" << x << "="
			<< log(x) << endl;
		break;
	case '8':
		cout << "Simple Calculator Out" << endl;
		break;

	default:
		cout << "Chose Something From The Menu";
	}
	return 0;

}
