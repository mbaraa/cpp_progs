#include <stdio.h>
// array size
#define ARRAY_SIZE(array) (sizeof(array) / sizeof((array)[0]))

// search an array using binary search
int binarySearch(int array[], int left, int right, int target) { 
    if (right >= left) { 
        int mid = left + (right - left) / 2; 
        // If the element is present at the middle 
        // itself 
        if (array[mid] == target) 
            return mid; 
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (array[mid] > target) 
            return binarySearch(array, left, mid - 1, target); 
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(array, mid + 1, right, target); 
    } 
    // We reach here when element is not 
    // present in array 
    return -1; 
} 
// search an array using linear search
int linearSearch(int array[], int size, int target){ 
    int i; 
    for (i = 0; i < size; i++) 
        if (array[i] == target) 
            return i; 

    return -1; 
} 
// search an array using sentinal linear search
int sentinelLinearSearch(int array[], int size, int target) { 
  
    // Last element of the array 
    int last = array[size - 1]; 
  
    // Element to be searched is 
    // placed at the last index 
    array[size - 1] = target; 
    int i = 0; 
  
    while (array[i] != target) 
        i++; 
  
    // Put the last element back 
    array[size - 1] = last; 
    
    // if the element is present then return its index otherwise return -1
    return ((i < size - 1) || (target == array[size - 1])) ? i : -1;
} 
int main(void){

    int array[] = {7, 5, 12, 99, -5, 46, 1, 0, -16};
    int size = ARRAY_SIZE(array);

    printf("element -5 is present at %d\n", binarySearch(array, 0, size -1 , -5));
    printf("element -5 is present at %d\n", linearSearch(array, size - 1, -5));
    printf("element -5 is present at %d\n", sentinelLinearSearch(array, size - 1, -5));

    return 0;
}
