#ifndef TETRISFUNCS_H
#define TETRISFUNCS_H

#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "kbInput.h"
#include "ioFuncs.h"

#define true 1
#define false 0


void dropOverColumn(char *matrix0, int rows, int columns) {
    // convert the given pointer to matrix
    char (*matrix)[columns] = matrix0;
    // start dropping from the first row
    int droppingRow = -1;
    // dropping starts from the middle
    int col = columns / 2;
    // print current tetris
    printMatrix(matrix, rows, columns);
    
    while( droppingRow < rows - 1 ) {
        
        // get current character from keyboard
        char chr = getch();
        // replace dropped character with a dot
        matrix[droppingRow++][col] = '.';
        // move left / right
        if(chr == 'A' || chr == 'a'){
        
            col--;
        
        } else if(chr == 'D' || chr == 'd'){
        
            col++;
        
        }


        clear();
        
        // add the dropping chararecter
        matrix[droppingRow][col] = '#';
        // print current tetris map
        printMatrix(*matrix, rows, columns);

        
    }

}

#endif //TETRISFUNCS_H