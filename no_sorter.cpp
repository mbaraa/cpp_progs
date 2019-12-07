#include <iostream>
using namespace std;
int main() {
	cout << "enter three numbers to sort (a,b,c): \n" << endl;
	int a,b,c;
	int no1 , no2 , no3 ,midmf , midmf2, lilmf;
	cin >> a >> b >> c;
	cout << "Chose Sort Type:\n"
		<< "1.Desascending\n"
		<< "2.Ascending\n";
	char sort;
	cin >> sort;
	switch(sort){
		case '1' :
			if (a > b && a > c)  {
        	        no1 = a ;
			midmf = b;
			midmf2 = c;
               		 	}
       			else if (b>c) {
                	no1 = b ;
			midmf = a;
			midmf2 = c;
              		  	}
       			else {
        	        no1 = c ;
			midmf = b;
			midmf2 = a;
                		}
			cout  << no1 << endl;
			
			if (midmf > midmf2){
        	        no2 = lilmf ;
			lilmf = midmf2;
               		 	}
       			else if (midmf2 > midmf) {
                	no2 = midmf2 ;
			lilmf = midmf;
              		  	}
			cout << midmf << endl;
			cout << lilmf << endl;
			
		case '2' :
			if (a < b && a < c)  {
        	        no1 = a ;
			midmf = b;
			midmf2 = c;
               		 	}
       			else if (b<c) {
                	no1 = b ;
			midmf = a;
			midmf2 = c;
              		  	}
       			else {
        	        no1 = c ;
			midmf = b;
			midmf2 = a;
                		}
			cout  << no1 << endl;
			
			if (midmf < midmf2){
        	        no2 = lilmf ;
			lilmf = midmf2;
               		 	}
       			else if (midmf2 < midmf) {
                	no2 = midmf2 ;
			lilmf = midmf;
              		  	}
			cout << midmf << endl;
			cout << lilmf << endl;
			
		}
	return 0;
	
}

