#ifndef TETRISFUNCS_H
#define TETRISFUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "kbInput.h"
#include "ioFuncs.h"
#include "Constants.h"

// initializers:

// initialize lengths with row length - 1
void initLengths(int *lengths) {
    for(int i = 0; i < COLUMNS; i++) {
        lengths[i] = ROWS - 1;
    } // for
} // void initLengths

// initialize completed lines with falses(0)
void initCompletedLines(bool *completedLines) {
    for(int i = 0; i < ROWS; i++) {
        completedLines[i] = 0;
    } // for
} // void initCompletedLines

// initialize tetris boolean map with falses(0)
void initCheckList(bool (*checkList)[COLUMNS]) {

    for(int row = 0; row < ROWS; row++) {
        
        for(int col = 0; col < COLUMNS; col++){
            checkList[row][col] = 0;
        } // inner for
    } // outer for
} // void initCheckList

// initialize tetris map with dots
void initTetrisMap(char (*tetrisMap)[COLUMNS]){

    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLUMNS; col++){
            
            tetrisMap[row][col] = '.';

        } // inner for
    } // outer for
} // void initTetrisMap

// replace true in boolean tetris map with #s in the tetris map
void updateTetrisMap(char (*tetrisMap)[COLUMNS],
                     bool (*checkList)[COLUMNS]) {

    for(int row = 0; row < ROWS; row++) {
        
        for(int col = 0; col < COLUMNS; col++){

            // (== 1) because for some reason the "if" fucks with the array and assigns some garbage values
            if( checkList[row][col] == 1 ) {
                tetrisMap[row][col] = '#';
            } // if
            
        } // for
    } // for

} // void updateTetrisMap

// replace #s in tetris map with trues
void checkTetrisMap(char (*matrix)[COLUMNS], bool (*checkList)[COLUMNS], int *lengths) {

    /* reversed checker to prevent stacked areas, 
     *   gone back to the original after having trouble with eliminateLines
     */
   for(int col = 0; col < COLUMNS; col++) {
        
        for(int row = 0; row < ROWS; row++){

            if( matrix[row][col] == '#' ) {
                
                checkList[row][col] = 1;
                lengths[col]--;
                //break;
                
            } // if
        } // inner for
    } // outer for

} // void checkTetrisMap

// if line is copleted mark its place in the completedLines array
void markDoneLines(bool (*tetrisBooleanMap)[COLUMNS],
                   bool *completedLines,
                   int *eliminatedLines) {

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

            // increase eliminated lines by one
            (*eliminatedLines)++;
            
            /*for(int col = 0; col < COLUMNS; col++){
 
               if( tetrisBooleanMap[row][col] != 1 ) {
                   break;
               }
               if( tetrisBooleanMap[row][9] == 1 ) {
                   
               }
            
           }*/

        } // crazy if
    } // outer for

} // void markDoneLines

// eliminate completed lines and shift upper lines down
void eliminateLines(char (*tetrisMap)[COLUMNS],
                    bool (*tetrisBooleanMap)[COLUMNS],
                    bool *completedLines,
                    int *columnsLengths) {

    // look for completed(filled) lines from down to up, it's more logical that way :)
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
            
            } // inner for1


            // shift rows down
            // remeber we're going downnnn to up
            for(int col = 0; col < COLUMNS; col++) {
                // rowEL is no spanish or mexican it's just (row at Eleminated Line)
                for(int rowEL = row ; rowEL > 0; rowEL--) {

                    tetrisMap[rowEL][col] = tetrisMap[rowEL-1][col];
                    tetrisBooleanMap[rowEL][col] = tetrisBooleanMap[rowEL-1][col];

                } // inner inner for            
            }// inner for 2         
            
        } // if
        
    } // outer for

} // void eliminateLines

// quit the game
void printGameOverAndGTFOH() {
    clear();
    // print red game over
    puts(RED);
    puts("GAME OVER !!!!");
    puts(RESET);
    exit(0);

} // void printGameOverAndGTFOH


void dropBlockOneRow(char (*tetrisMap)[COLUMNS],
                     Tetromino *block,
                     int currX, int currY,
                     int destX) {
                     //int rotation) {

    
    int *x = &block->x;
    int *y = &block->y;
    
    // draw equivalent empty block on the tetris map
    for(int shapeRow = 0; shapeRow < block -> height; shapeRow++) {
        
        for(int shapeCol = 0; shapeCol < block -> width; shapeCol++) {
            
            tetrisMap[*y + shapeRow][*x + shapeCol] = block -> eqNone[shapeRow][shapeCol];

        } //

    } //

    // update coordinates
    block -> x = destX;
    block -> y++; // drop one block
    
    // draw block on the tetris map
    for(int shapeRow = 0; shapeRow < block -> height; shapeRow++) {
        
        for(int shapeCol = 0; shapeCol < block->width; shapeCol++) {
            
            tetrisMap[*y + shapeRow][*x + shapeCol] = block -> shape[shapeRow][shapeCol];

        } //

    } //
            

} // void dropBlockOneRow

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