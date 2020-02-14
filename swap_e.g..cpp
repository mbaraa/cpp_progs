#include<iostream>
using namespace std;
void swap1(int&,int&);
void swap2(int&,int&);

int main(){
	int x,y;
	cout << "Enter two number to swap:    \n";
	cin >> x >> y;
	swap1(x,y);
	cout << "first swap    " << x << " " << y << endl;
	swap2(x,y);
	cout << "second swap    " << x << " " << y << endl;
};
void swap1(int& x , int& y){
	int temp = x;
	x = y;
	y = temp;
}
void swap2(int& x , int& y){
	x += y;
	y = x - y;
	x = x - y;
}
