//Digit Seperator
#include <iostream>
#include <math.h>
using namespace std;
double digCheck(double x);
int main(){
	int sum=0;
	long long int no,sep,digi;
	cout << "Input a number :\n";
	cin >> no;
	digi = digCheck(no) ;
	for(int i=1 ; i <= digi ; digi-- ){
		
		long long int mf = pow(10,digi - 1);	
		sep = no / mf % 10 ;
		cout << sep << "  ";
		sum += sep; 
	}
	cout << "\nSum of the digits : " << sum << endl;
	return 0;
}

double digCheck(double x){
	long long int digi = 0;
	while(x > 1){
		x /= 10;
		digi++;
	}
	return digi ;
	
}
