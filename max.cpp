#include <iostream>;
using namespace std;
int main() {
	int x,y,m;
	cin >> x >> y;
	m = x - y;
	if (m > 0) {
		cout << "max =" << x;
	}else if (m < 0) {
		cout << "max =" << y;
	}
	return 0;
}
