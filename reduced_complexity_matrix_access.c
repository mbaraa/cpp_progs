#include <stdio.h>
void readMatrix(void *matrixPtr, size_t rows, size_t columns);
void printMatrix(void *matrixPtr, size_t rows, size_t columns);

int main(void){
    int rows, cols;
    rows = 3;
    cols = 3;
    double array[rows][cols];
    readMatrix(array, rows, cols);
    printMatrix(array, rows, cols);
    return 0;
}

// super slavic read matrix function
void readMatrix(void *matrixPtr, size_t rows, size_t columns){
    // matrixPtr is a pointer to the 2d array
    // assigning a new array with the location of the given array
    // and the rest is history
    double (*matrix)[columns] = matrixPtr;
    // counter to stop the loop :)
    int counter = 0;
    // row & column counters for the array
    size_t row, column;
    for (column = 0, row = 0; row < rows ; column++){
        // shift through the rows
        if (column > columns - 1){
            row++;
            column = 0;
        }
        // update matrix elements
        scanf("%lf", &matrix[row][column]);
        // update counter
        counter++;
        // exit the loop if counter == order of the matrix
        if (counter == rows*columns)
            break;
    }

}

// super slavic print matrix function
void printMatrix(void *matrixPtr, size_t rows, size_t columns){
    // matrixPtr is a pointer to the 2d array
    // assigning a new array with the location of the given array
    // and the rest is history
    double (*matrix)[columns] = matrixPtr;
    // counter to stop the loop :)
    int counter = 0;
    // row & column counters for the array
    size_t row, column;
    for (column = 0, row = 0; row < rows ; column++){
        // shift through the rows
        if (column > columns - 1){
            row++;
            column = 0;
            // give it a matrix style
            printf("\n");
        }
        // update matrix elements
        printf("%lf ", matrix[row][column]);
        // update counter
        counter++;
        // exit the loop if counter == order of the matrix
        if (counter == rows*columns)
            break;
    }
    // for formatting
    printf("\n");

}
