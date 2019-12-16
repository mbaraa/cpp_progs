#include <iostream>

using namespace std;

int main()
{
	int i, j, k,n;
	cout << "Input number of itirations:\n";
	cin >> n;  
	for (i = 1; i <= n; i++) {
		for (j = n; j >=  i; j--){
			cout << " ";
		}
			for(k = 1 ;k <=i ;k++){
				cout << "*";
			}
		cout << endl;
	}
	return 0;
}
