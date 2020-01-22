//generalize me please b****
#include<iostream>
#include<string>
using namespace std;
int main() {
	char id[3] = {'n1','n2','n3'};
	int first[3], second[3], total[3];
	cout << "enter 1st exam mark\n";
	for (int i = 0; i < 3; i++) {
		cin >> first[i];
	}	
	cout << "enter 2nd exam mark\n";

	for (int i = 0; i < 3; i++) {
		cin >> second[i];
	}
	for (int i = 0; i < 3; i++) {
		total[i] = first[i] + second[i];
	}

	int max = total[0] , loc = 0;
	for (int i = 0; i < 3; i++) {
		if (total[i] > max) {
			max = total[i];
			loc = i;
		}
	}
	cout << "Max mark is : " << max << " of the student : " << id[loc];
	return 0;
}
