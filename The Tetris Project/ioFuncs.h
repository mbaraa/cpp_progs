#ifndef IOFUNCS_H
#define IOFUNCS_H

#include <stdio.h>
#include "Constants.h"

// red color output
#define RED "\033[31m"
// reset color output
#define RESET "\033[0m"

void clear() {
    printf("\033[H\033[2J");
}

void printMatrix(char (*matrix)[COLUMNS], int rows, int columns){


    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < columns; col++){
            
            printf("%c ", matrix[row][col]);

        }
    
        printf("\n");
    
    }
}

void swap(int *x , int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

#endif //IOFUNCS_H