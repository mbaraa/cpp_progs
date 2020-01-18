#include<iostream>
using namespace std;
int main(){
	int n,max1,max2,max3;
	cout << "Enter size of an array : \n";
	cin >> n;int a[n];
	cout << "Enter array's elements : \n";
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	max1 = a[0];
	max3 = a[1];
	max2 = a[2];
	for(int i = 1;i<n;i++){
		if(a[i]>max1){
			max1=a[i];
		}
		if(a[i]>max2 && a[i]<max1){
			max2=a[i];
		}
		if(a[i]>max3 && a[i]<max2){
			max3=a[i];
		}
	}
	cout << "Array's elements : \n";
	for(int i = 0;i<n;i++){
		cout << a[i]<<" ";
	}
	cout << endl << "The three largest values in array : \n";
	cout << max1 <<" " << max2 <<" "<< max3;
};
