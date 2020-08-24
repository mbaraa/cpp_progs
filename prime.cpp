#include<iostream>
#include <vector>
using namespace std;

template <typename type>
ostream& operator<<(ostream& os, vector<type> vec){
    os << "[";
    
    for (int i = 0; vec[i] != 0; ++i) { 
        os << vec[i]; 
        
        os << (vec[i+1] != 0? ",": ""); 
  
    }
    
    os << "]";
    return os;
}

int main (){
	cout << "Enter a number: ";
	int no;
	bool prime = 1;
	string state;
	cin >> no ;

    //int nDivisors[(int)(no/2)];    
    vector<int> nDivisors((int)(no/2));    
    int nDivCounter = 0;

	for(int i = 2 ; i <= no / 2 ; i++){
		if(no % i == 0){
			prime = 0;
            nDivisors[nDivCounter] = i;
            nDivCounter++;
			
		}
	}


	if(prime)
		cout << "Prime!\n";
	else {
		cout << "Not a prime!\n";
        cout << "Divisors:"  << nDivisors << endl;
    }
    
    return 0 ;

}
