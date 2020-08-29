#include <stdio.h> 
#include <limits.h> 
#include <math.h>
  
int max(int x, int y) {
    return x > y? x: y;
}

// Find the maximum possible sum in arr[] auch that arr[m] is part of it 
int maxCrossingSum(int *array, int left, int midPoint, int right) { 
    
    // Include elements on left of mid. 
    int sum = 0; 
    int leftSum = INT_MIN; // - infinity
    for (int i = midPoint; i >= left; i--) { 
        sum = sum + array[i]; 
        if (sum > leftSum) 
          leftSum = sum; 
    } 
  
    // Include elements on right of mid 
    sum = 0; 
    int rightSum = INT_MIN; 
    for (int i = midPoint + 1; i <= right; i++) { 
        sum = sum + array[i]; 
        if (sum > rightSum) 
          rightSum = sum; 
    } 
  
    // Return sum of elements on left and right of mid 
    // returning only left_sum + right_sum will fail for [-2, 1] 
    return max( max(leftSum + rightSum, leftSum), rightSum); 
} 
  
// Returns sum of maxium sum subarray in aa[l..h] 
int maxSubArraySum(int *array, int left, int right) { 
    // Base Case: Only one element 
    if (left == right) { 
        return array[left]; 
    }

    // Find middle point 
    int m = (left + right)/2; 
  
    /* Return maximum of following three possible cases 
      a) Maximum subarray sum in left half 
      b) Maximum subarray sum in right half 
      c) Maximum subarray sum such that the subarray crosses the midpoint */
    
    return max(max (maxSubArraySum(array, left, m), 
              maxSubArraySum(array, m+1, right) ), 
              maxCrossingSum(array, left, m, right)); 
} 

void initArrayWithMin(int *array, int size) {

    for (int i = 0; i < size; i++) {
        array[i] = INT_MIN;
    }

}

int *getMaxSubArray(int *array, int left, int right) {

    int maxSum = maxSubArraySum(array, left, right);

    int m = (left + right) / 2;

    int start, end;

    // left array
    if (maxSum == maxSubArraySum(array, left, m) ) {
        start = left;
        end = m;

    }
    // right array
    else if (maxSum == maxSubArraySum(array, m + 1, right)) {

        start = m+1;
        end = right;

    }
    // crossing array
    else if (maxSum == maxCrossingSum(array, left, m, right)) {

        start = left;
        end = right;

    }   
 

    // store and return the array with the maximum sum
    static int maxSubArray[1000000];
    initArrayWithMin(maxSubArray, 1000000);

    for (int i = start, j = 0; i <= end; i++, j++) {
        maxSubArray[j] = array[i];
    }

    return maxSubArray;

}

// driver
int main() {

    int arr[] = {2, 3, -4, 5, -6}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int max_sum = maxSubArraySum(arr, 0, n-1); 

    printf("Maximum contiguous sum is %d\n", max_sum); 

    int *maxshit = getMaxSubArray(arr, 0, n-1);

    for (int j = 0; maxshit[j+1] != INT_MIN; j++) {
        printf("%d ", maxshit[j]);        
    }

    return 0; 
} 