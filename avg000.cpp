#include <iostream>
using namespace std;
int main() {
	int v= 0 ,a;
	cout << "Enter 5 Integer:\n";
	double sum = 0, avg ;
	while (v < 5) {
		cin >> a;
		sum = sum + a;
		v++;
	}
	avg = sum / v;
	cout << avg;
	cout << "\nDone" << endl;
	return 0;
}
