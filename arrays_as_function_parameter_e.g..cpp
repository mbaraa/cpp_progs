#include<iostream>
using namespace std;
void readArray(int a[], int);
void printArray(int a[], int);
int sumArray(int a[], int);
void copyArray(int a[], int b[],int);

int main() {
	int a[10], b[10];
	cout << "Input values for array1 : \n";
	readArray(a, 10);
	cout << "values of array1 : \n";
	printArray(a, 10);
	cout << "Copying values of array1 to array2 .... \n";
	copyArray(a, b, 10);
	cout << "Input values for array2 : \n";
	printArray(b, 10);
	cout << "Sum of values for array1 : \n";
	cout << sumArray(a, 10) << endl;
	cout << "Sum of values for array2 : \n";
	cout << sumArray(b, 10) << endl;

	return 0;
}
void readArray(int a[], int size) {
	for (int i = 0; i < size; i++) {
		cin >> a[i];
	}
	cout << endl;

}



void printArray(int a[], int size) {
	for (int i = 0; i < size; i++) {
		cout << a[i];
	}
	cout << endl;
}
int sumArray(int a[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += a[i];
	}
	return sum;
}
void copyArray(int a[], int b[], int size) {
	for (int i = 0; i < size; i++) {
		b[i] = a[i];
	}
	cout << endl;

}
