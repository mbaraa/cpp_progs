#include<iostream>
#include<string>
#include<unistd.h>
using namespace std;
int main(){
	string star ("*") ;
	string nigger ("**");
	for (int i=0 ; ; i++){
						
		cout << star << endl;
		usleep(500000);
		star += nigger;
		}
	return 0 ;
}
