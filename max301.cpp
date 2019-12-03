#include <iostream>
using namespace std;
int main() {
	cout << "enter three numbers to compare:\n";
	int x,y,z;
	cin >> x >> y >> z;
	if (x>y) { 
		if(x>z) { 
			cout << "max = " << x << endl;
			} 
		else { cout << "max = " << z << endl;
			}
		}
	
	else if (y>x) { 
		if (y>z) {
		cout << "max = " << y << endl;
			} 
		else { cout << "max = "<< z << endl;
			}
	}
	return 0;
}
