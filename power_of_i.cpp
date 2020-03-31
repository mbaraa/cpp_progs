#include <iostream>
using namespace std;
int main(){
	cout << "Program is terminated by E.O.F!\n";
	while(true){
		cout << "Enter the desierd power of i:\t";
		int power;
		cin >> power;
		if (power % 4 == 0)
			cout << "i^" << power << " = " << "1" << endl;
		else if (power % 4 == 1)
			cout << "i^" << power << " = " << "i" << endl;
		else if (power % 4 == 2)
			cout << "i^" << power << " = " << "-1" << endl;
		else if (power % 4 == 3)
			cout << "i^" << power << " = " << "-i" << endl;
	}
	
    return 0;
}
