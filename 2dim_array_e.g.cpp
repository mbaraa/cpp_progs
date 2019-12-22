#include <iostream>;
using namespace std;
int  main(){
	int list[3][2];
	int j ,i;
	cout << "enter some numerical vsalus \n";
	for(i = 0 ; i < 3 ; i++){		
		for(j=0 ; j < 2 ; j++){
			cin >> list[i][j];
		}
	}
	for(i = 0 ; i < 3 ; i++){
		for(j=0 ; j < 2 ; j++){
			cout << list[i][j]<<" ";
		}
	}
	return 0;
}
