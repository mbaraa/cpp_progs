#include<iostream>
using namespace std;
int main() {
	char ch;
	int A = 0, a = 0, no = 0, sym = 0;
	cout << "\nInput a Character to start (not included in the counting) :\n";
	cin >> ch;
	bool out = 1;

	while (out) {
		cout << "\nInput a Character, input \"#\" to exit\n";
		cin >> ch;

		if (ch == '#') {
			out = 0;
		}
		else if ((ch >= '!' && ch <= '.') || (ch >= ':' && ch <= '@') || (ch >= '[' && ch <= 96) || (ch >= '{' && ch <= '~')) {
			sym++;
		}
		else if (ch >= '0' && ch <= '9') {
			no++;
		}

		else if (ch >= 'A' && ch <= 'Z') {
			A++;
		}

		else if (ch >= 'a' && ch <= 'z') {
			a++;
		}

	}
	cout << "\nUpper Cases: " << A
		<< "\nLower Cases: " << a
		<< "\nNumbers: " << no
		<< "\nSymbols: " << sym;



	return 0;
}
