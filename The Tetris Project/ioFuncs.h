#ifndef IOFUNCS_H
#define IOFUNCS_H

#include <stdio.h>
#include "GlobalsAndConstants.h"

void clear() {
    printf("\033c");
}

void printMatrix(char *matrix, int rows, int columns){


    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < columns; col++){
            
            printf("%c ", *((matrix + row*COLUMNS) +col));

        }
    
        printf("\n");
    
    }
}


#endif //IOFUNCS_H