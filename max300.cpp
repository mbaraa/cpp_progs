#include <iostream>
using namespace std;
int main() {
	cout << "enter three numbers to compare: \n" << endl;
	int x,y,z;
	cin >> x >> y >> z;
	if (x > y > z) {
		cout << "max = " << x << endl;
		} 
	else if (y>z) { 
		cout << "max = " << y << endl;
		}
	else { 
		cout << "max = " << z << endl;
		}
	return 0;
}
