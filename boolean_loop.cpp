#include <iostream>
using namespace std;
int main() {
	bool flag = 1;
	int no, sum = 0;
	while (flag) {
		cout << "Enter a number if number is divisiable by 3 quit:\n";
		cin >> no;
		if (no % 3 == 0)
			flag = 0;
		else sum += no;
	}
	cout << sum;
	return 0;
}