//to be rectified in the future
#include<iostream>
using namespace std;
int main(){
    cout << "Enter array size :   ";
    int size;
    cin >> size;
    int a[size];
    int na[size];
    int min=a[0] , max=a[0];
    cout << "Enter array's component :  ";
    for(int i = 0 ; i<size ; i++){
        cin >> a[i];
    }
    for(int i=0;i<size;i++){
    if(a[i]>max){
            max=a[i] + 1;
        }
    }
    int loc;
    for(int i=0;i<5;i++){
        for(int j = 0;j<5;j++){
            if(a[j]<min){
                min=a[j];
                loc = j;
            }
        }
        na[i]=min;
        a[loc]=max;
        min=max;
    }
    for(int i=0;i<5;i++){
        cout << na[i] << " ";
    }

};


