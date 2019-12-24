#include <iostream>;
using namespace std;
int  main(){
	int list[3][2];
	int j ,i;
	cout << "enter some numerical vsalus \n";
	//this loop for rows
	for(i = 0 ; i < 3 ; i++){		
		//this loop for colomns
		for(j=0 ; j < 2 ; j++){
			cin >> list[i][j];
		}
	}
	//this loop for rows
	for(i = 0 ; i < 3 ; i++){
		//this loop for colomns
		for(j=0 ; j < 2 ; j++){
			cout << list[i][j]<<" ";
		}
	}
	return 0;
}
