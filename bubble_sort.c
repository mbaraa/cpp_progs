#include <stdio.h>
#define SIZE(array) (sizeof(array) / sizeof((array)[0]))
// sort an array using bubble sort algorithm
void bubble_sort(int array[], int array_size){ // O(n^2), where b is size of the array
    int walk_through; // walk through array
    int index;
    int temp; // to hold the element while swapping

    // begin action
    // this outer loop walks through the array to make sure that it's sorted :)
    for( walk_through = 1; walk_through < array_size; walk_through++ ){
        // this inner loop swaps two adjacent elements if not sorted
        for( index = 0; index < array_size - 1; index++ ){
            if( array[index] > array[index + 1] ){
                temp = array[index];
                array[index] = array[index + 1];
                array[index + 1] = temp;
            } // if
        } // inner loop
    } // outer loop
}
// print function no explain needed
void print_array(int array[], int array_size){
    int index;
    for(index = 0; index < array_size; index++)
        printf("%d ", array[index]);
    
    printf("\n");
}

int main(void){
    // some array to test
    int a[] = {7, 5, 12, 99, -5, 46, 1, 0, -16};
    printf("array before sorting: \n");
    print_array(a, SIZE(a) );

    printf("\narray after sorting: \n");
    bubble_sort(a, SIZE(a));
    print_array(a, SIZE(a));

    return 0;
}
