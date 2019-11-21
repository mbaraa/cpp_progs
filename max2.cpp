#include <iostream>;
using namespace std;
int main() {
	int x,y; 
	cout << "Enter two integers to test: \n";
	cin >> x >> y;
	if (x > y) {
		cout << "max = " << x << endl;
		}
	else { cout << "max = " << y << endl;
	}
	return 0;
}
