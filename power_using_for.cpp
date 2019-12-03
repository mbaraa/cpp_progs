#include <iostream>
using namespace std;
int main() {
	int i=1 ,c;
	double p,no;
	cout << "Enter a number:\n";
	cin >> no;
	cout << "Enter the desired power:\n";
	cin >> p;
	for(c=1 ; c <= p ; c++){
		i = i*no;
		}
	cout << i << endl;
	return 0 ;
}
