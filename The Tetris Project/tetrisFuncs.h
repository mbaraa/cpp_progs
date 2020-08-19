#ifndef TETRISFUNCS_H
#define TETRISFUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "kbInput.h"
#include "ioFuncs.h"
#include "Constants.h"

// initializers
void initLengths(int *lengths) {
    for(int i = 0; i < COLUMNS; i++) {
        lengths[i] = 19;
    }
}

void initCompletedLines(bool *completedLines) {
    for(int i = 0; i < ROWS; i++) {
        completedLines[i] = 0;
    }
}

void initCheckList(bool (*checkList)[COLUMNS]) {

    for(int row = 0; row < ROWS; row++) {
        
        for(int col = 0; col < COLUMNS; col++){

            checkList[row][col] = 0;
        }
    
    }
}

void initTetrisMap(char (*matrix)[COLUMNS]){

    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLUMNS; col++){
            
            matrix[row][col] = '.';

        }
    
    }
}

// replace true in boolean tetris map with #s
void updateTetrisMap(char (*matrix)[COLUMNS], bool (*checkList)[COLUMNS]) {

    for(int row = 0; row < ROWS; row++) {
        
        for(int col = 0; col < COLUMNS; col++){

            // (== 1) because for some reason the "if" fucks with the array and assigns some garbage values
            if( checkList[row][col] == 1 ) {
                matrix[row][col] = '#';
            }
            
        }
    }

}

// replace #s in tetris map with trues
void checkTetrisMap(char (*matrix)[COLUMNS], bool (*checkList)[COLUMNS], int *lengths) {

    // reversed checker to prevent stacked areas
    for(int col = 0; col < COLUMNS; col++) {
        
        for(int row = 0; row < ROWS; row++){

            if( matrix[row][col] == '#' ) {
                
                checkList[row][col] = 1;
                lengths[col]--;
                //break;
                
            }
        }
    }

}

void markDoneLines(bool (*tetrisBooleanMap)[COLUMNS],
                   bool *completedLines) {

    for(int row = 0; row < ROWS; row++) {
        
        // (== 1) because for some reason the "if" fucks with the array and assigns some garbage values
        if( tetrisBooleanMap[row][0] == 1 && 
            tetrisBooleanMap[row][1] == 1 && 
            tetrisBooleanMap[row][2] == 1 && 
            tetrisBooleanMap[row][3] == 1 && 
            tetrisBooleanMap[row][4] == 1 && 
            tetrisBooleanMap[row][5] == 1 && 
            tetrisBooleanMap[row][6] == 1 && 
            tetrisBooleanMap[row][7] == 1 && 
            tetrisBooleanMap[row][8] == 1 &&
            tetrisBooleanMap[row][9] == 1 ) {
            
            // I fucked up here not gonna lie
            completedLines[row] = 1;
            /*for(int col = 0; col < COLUMNS; col++){
 
               if( tetrisBooleanMap[row][col] != 1 ) {
                   break;
               }
               if( tetrisBooleanMap[row][9] == 1 ) {
                   
               }
            
           }*/
        }
    }

}

void eliminateLines(char (*tetrisMap)[COLUMNS],
                    bool (*tetrisBooleanMap)[COLUMNS],
                    bool *completedLines,
                    int *columnsLengths) {

    
    for(int row = ROWS - 1; row >= 0; row--) {
        
        // (== 1) because for some reason the "if" fucks with the array and assigns some garbage values
        if( completedLines[row] == 1 ) {
            
            // set completion state to false
            completedLines[row] = 0;
            
            // reset line
            for(int col = 0; col < COLUMNS; col++) {
                tetrisMap[row][col] = '.';
                tetrisBooleanMap[row][col] = 0;
                // since there's an eleminated line so lengths are increased
                columnsLengths[col]++;
            }

            //updateTetrisMap(tetrisMap, tetrisBooleanMap);

            // shift rows down
            // remeber we're going downnnn to up
            for(int col = 0; col < COLUMNS; col++) {
                
                for(int rowEL = row ; rowEL > 0; rowEL--) {

                    tetrisMap[rowEL][col] = tetrisMap[rowEL-1][col];
                    tetrisBooleanMap[rowEL][col] = tetrisBooleanMap[rowEL-1][col];
                    

                }                

            }
         
       /*     for(int rowEL =  row ; rowEL > 0; rowEL--) {

                for(int col = 0; col < COLUMNS; col++) {
                    
                    tetrisMap[rowEL][col] = tetrisMap[rowEL-1][col];
                    tetrisBooleanMap[rowEL][col] = tetrisBooleanMap[rowEL-1][col];

                }
                

            }*/
            
        }
        
    }

}

void printGameOverAndGTFOH() {
    //clear();

    puts(RED);
    puts("GAME OVER !!!!");
    puts(RESET);
    exit(0);
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