#include <iostream>
#include <unistd.h>
using namespace std;
int main(){
	int destiny;
	double timer = 1;
	cout << "Chose timer type:" 
	<< "\n1.Finite"
	<< "\n2.Infinite"<< endl;
	cin >> destiny ;
	if(destiny == 1){
		int value;
		cout << "Input timer\'s value" << endl ;
		cin >> value;
		for(; timer <= value ; timer += 0.01){
			cout << timer << endl;
			usleep(10000);
			}
		}

	else if(destiny == 2){
		for( ; ; timer += 0.01){
			cout << timer << endl;
			usleep(10000);
			}
		}
	else
		cout << "\nStick to the choices idiot.";
	
	return 0;
}
			
