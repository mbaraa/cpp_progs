//Rectified
#include<iostream>
using namespace std;
int main(){
    cout << "Enter array's size :   ";
    int arraySize;
    cin >> arraySize;
    
    double array[arraySize];
    double min=array[0] , max=array[0];
    
    cout << "Enter array's components:  ";
    for(int counter = 0 ; counter < arraySize ; counter++){
        cin >> array[counter];
        if(array[counter]>max){
            max=array[counter] + 1;
        }
    }

    int loc;
    double sortedArray[arraySize];

    for(int outercounter = 0 ; outercounter < arraySize ; outercounter++){
        for(int innercounter = 0  ; innercounter < arraySize ; innercounter++){
            if(array[innercounter]<min){
                min=array[innercounter];
                loc = innercounter;
            }
        }
        sortedArray[outercounter]=min;
        array[loc]=max;
        min=max;
    }
    for(int counter = 0 ; counter < arraySize ; counter++){
        cout << sortedArray[counter] << " ";
    }

};
