#include <iostream>;
using namespace std;
int main() {
	cout << "enter three numbers to compare: \n" << endl;
	int x,y,z,g;
	cin >> x >> y >> z;
	if (x-y>0) {
		cout << "max = " << x << endl;
		}
	
	else if (z>y) {
		cout << "max = " << z << endl;
		
	}
	else {
		cout << "max = " << y << endl;
	}
	
	
	return 0;
}
