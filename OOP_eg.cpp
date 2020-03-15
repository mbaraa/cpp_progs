#include<iostream>
using namespace std;
//class definition
class Point{
//modifier type
public:
	//declaring variables in the class
	double x , y;
	//declaring a function in the class
	void print(){
		cout << "X axis: " << x << " Y axis: " << y << endl;
	}
};//end of class

int main(){
	//declaring an object called p1
	Point p1;
	//using variables from the class
	cin >> p1.x >> p1.y;
	//usign function from the class
	p1.print();
	//same here
	Point p2;
	cin >> p2.x >> p2.y;
	p2.print();
	
    return 0;
}
