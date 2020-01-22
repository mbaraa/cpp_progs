#include <iostream>
using namespace std;
int main() {
	double v= 0 ,a,l;
	cout << "Enter Number of Integers:\n";
	cin >> l;
	cout << "Enter " << l << " Integer:\n" << endl;
	double sum = 0, avg ;
	while (v < l) {
		cin >> a;
		sum = sum + a;
		v++;
	}
	avg = sum / l;
	cout << "\nAverage = " << avg;
	cout << "\nDone" << endl;
	return 0;
}
