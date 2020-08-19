#ifndef TETRISFUNCS_H
#define TETRISFUNCS_H

#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "kbInput.h"
#include "ioFuncs.h"
#include "GlobalsAndConstants.h"


void initLengths(int lengths[]) {
    for(int i = 0; i < 10; i++) {
        lengths[i] = 19;
    }
}

void initCheckList(bool *checkList) {
    //bool (*checkList)[10] = checkList0;

    for(int row = 0; row < 20; row++) {
        
        for(int col = 0; col < 10; col++){

            *((checkList + row*COLUMNS ) + col) = 0;
        }
    
    }
}

void initMatrix(char *matrix, int rows, int columns){

    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < columns; col++){
            
            *( (matrix + row*COLUMNS ) +col ) = '.';

        }
    
    }
}

void updateTetrisMap(char *matrix, bool *checkList, int rows, int columns) {


    for(int row = 0; row < rows; row++) {
        
        for(int col = 0; col < columns; col++){

            // (== 1) because for some reason the "if" fucks with the array and assigns some garbage values
            if( *(( checkList + row*COLUMNS) + col) == 1 ) {
                *(( matrix + row*COLUMNS) + col) = '#';
                
            }

        }
    
    }

}

void checkTetrisMap(char *matrix, bool *checkList, int rows, int columns, int lengths[]) {

    for(int col = 0; col < columns; col++) {
        
        for(int row = 0; row < rows; row++){

            if( *((matrix + row*COLUMNS ) + col) == '#' ) {
                
                *((checkList + row*COLUMNS ) + col) = 1;
                lengths[col]--;
                break;
                
            }

        }
    
    }

}

/* not needed for now :)
void dropOverColumn(char *matrix0, int rows, int columns) {
    
    // start dropping from the first row
    int droppingRow = -1;
    // dropping starts from the middle
    int col = columns / 2;
    // print current tetris
    printMatrix(*matrix, rows, columns);
    
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

        // setting boundaries
        if( col >= 9 ){
        
            col = 9;
        
        } else if( col <= 0 ) {

            col = 0;

        }


        clear();
        
        // add the dropping chararecter
        matrix[droppingRow][col] = '#';
        // print current tetris map
        printMatrix(*matrix, rows, columns);

        
    }

}
*/
#endif //TETRISFUNCS_H