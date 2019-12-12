#include<iostream>
using namespace std;
int primer(int);
int main (){
	cout << "Enter an Interval [a,b]:\n";
	int a,b;
	int pno=0,npno=0;
	cin >> a >> b ;
	bool state ;
	for(int j = a; j <= b;j++){
		state = primer(j);
		if(state){
			pno++;
		}
		else{
			npno++;
		}
	
	}
	cout << "\nNonPrimes :"<<npno << endl;
	cout << "\nPrimes :"<<pno << endl;
	return 0 ;

}	

int primer(int no){
	bool state = 1;
	for(int i = 2 ; i <= no / 2 ; i++){
	           
		if(no % i == 0){
                       	state = 0;
			break;	
			}
		}
	  		 
	return state ;
}
