#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main(){
	//using Leibniz formula http://q.gs/F8BgW
	double pi=0 , k=0;
	do{
		pi += ( pow(-1,k)/( 2*k + 1 ) );
		if ( pi*4 > 3.14 ){
			cout << "π = " << setprecision(50) << fixed << 4*pi << endl;
		}
		k++;
	
	}while(true);


    return 0;
}
