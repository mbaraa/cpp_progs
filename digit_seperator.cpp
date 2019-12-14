//Digit Seperator
#include <iostream>
#include <math.h>
using namespace std;
int digCheck(int x);
int main(){
	int no,sep,digi,sum=0;
	cout << "Input a number :\n";
	cin >> no;
	digi = digCheck(no) ;
	for(int i=1 ; i <= digi ; digi-- ){
		
		int mf = pow(10,digi - 1);	
		sep = no / mf % 10 ;
		cout << sep << "  ";
		sum += sep; 
	}
	cout << "\nSum of digits : " << sum << endl;
	return 0;
}

int digCheck(int x){
	int digi = 0;
	while(x > 1){
		x /= 10;
		digi++;
	}
	return digi ;
	
}
