#include<iostream>
using namespace std;
int main() {
	char ch;
	int A=0,a=0,no=0,sym=0;
	cout << "\nInput a Character to start\n" ;
	cin >> ch;
	bool out = 1;

	while (out){
	cout << "\nInput a Sentence to sort\n" ;
	cin >> ch;		

	if ((ch>=33 && ch<=47) || (ch>=58 && ch<=64) || (ch>=91 && ch<=96) || (ch>=123 && ch<=126)){
		sym++;
		continue;
		}
	else if (ch>=48 && ch<=57){
		no++;
		continue;
		}
	
	else if (ch>=65 && ch<=90){
		A++;
		continue;
		}
	
	else if (ch>=97 && ch<=122){
		a++;
		break;
		}

	}
	cout << "\nUpper Cases " << A
             << "\nLower Cases " << a 
	     << "\nNumbers " << no 
	     << "\nSymbols " << sym; 



	return 0 ;
}
