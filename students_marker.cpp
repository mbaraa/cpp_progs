//Rectified
#include<iostream>
#include<string>
using namespace std;
int main() {
	cout << "Enter number of students : ";
	int mfs; cin >> mfs; cout<<endl;
	string id[mfs];
	cout << "enter students' IDs\n";
	for(int i=0 ;i<mfs;i++){
		cin >> id[i];
	}
	int first[mfs], second[mfs], total[mfs];
	cout << "enter 1st exam mark\n";
	for (int i = 0; i < mfs; i++) {
		cin >> first[i];
	}	
	cout << "enter 2nd exam mark\n";

	for (int i = 0; i < mfs; i++) {
		cin >> second[i];
	}
	for (int i = 0; i < mfs; i++) {
		total[i] = first[i] + second[i];
	}

	int max = total[0] , loc = 0;
	for (int i = 0; i < mfs; i++) {
		if (total[i] > max) {
			max = total[i];
			loc = i;
		}
	}
	cout << "Max mark is : " << max << " of the student : " << id[loc] << endl;
	return 0;
}
