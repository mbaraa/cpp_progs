#include<iostream>
using namespace std;
int max(int a,int b); // forward declaration for the function max

int main() {
	int x,y;

	cout << "Input Two Number To Compare:\n";
	cin >> x >> y;
	int m = max(x,y); //Calling the function max
	cout << "\nMax = "<< m << endl ;
	return 0 ;
}

int max(int a , int b){
	if(a>b)
		return a;
	else
		return b;
}
