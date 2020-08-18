#ifndef IOFUNCS_H
#define IOFUNCS_H

#include <stdio.h>

void clear() {
    printf("\033c");
}

void printMatrix(char *matrix0, int rows, int columns){

    char (*matrix)[columns] = matrix0;

    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < columns; col++){
            
            printf("%c ", matrix[row][col]);

        }
    
        printf("\n");
    
    }
}

void initMatrix(char *matrix0, int rows, int columns){

    char (*matrix)[columns] = matrix0;

    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < columns; col++){
            
            matrix[row][col] = '.';

        }
    
    }
}

#endif //IOFUNCS_H