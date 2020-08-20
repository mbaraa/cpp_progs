#include "tetrisFuncs.h"
#include "Constants.h"
#include "Tetrominos.h"

int main() {
/*
    Tetromino square;

    square.height = 2;
    square.width = 2;
    square.shape[0][0] = '#';
    square.shape[0][1] = '#';
    
    square.shape[1][0] = '#';
    square.shape[1][1] = '#';

    /////
    square.eqNone[0][0] = '.';
    square.eqNone[0][1] = '.';

    square.eqNone[1][0] = '.';
    square.eqNone[1][1] = '.';

    Tetromino stick;

    stick.height = 4;
    stick.width = 1;
    stick.shape[0][0] = '#';
    stick.shape[1][0] = '#';
    
    stick.shape[2][0] = '#';
    stick.shape[3][0] = '#';

    /////
    stick.eqNone[0][0] = '.';
    stick.eqNone[1][0] = '.';

    stick.eqNone[2][0] = '.';
    stick.eqNone[3][0] = '.';
*/

    char tetrisMainMap[ROWS][COLUMNS];
    // mark each taken place with true(1)
    bool checkList[ROWS][COLUMNS];
    // columns lengths
    int colsLengths[COLUMNS];
    // completed rows
    bool completedLines[ROWS];
    // lines eliminated
    int lines = 0;

    initLengths(colsLengths);
    initCheckList(checkList);
    initTetrisMap(tetrisMainMap);
    initCompletedLines(completedLines);

    //dropOverColumn(m, 20, 10);

    // start dropping from the first row
    int droppingRow = -1;
    // dropping starts from the middle
    int col = COLUMNS / 2 - 1;

    // print current tetris
    printMatrix(tetrisMainMap, ROWS, COLUMNS);

    square.x = 4;
    square.y = 0;
    
    straight.x = 4;
    straight.y = 0;

    int newCol = col;
    
    while( true ) {

        square.y = droppingRow - square.height - 1; // height - 1 
        straight.y = droppingRow - 3;//stick.height - 1;
        lShape.y = droppingRow - 2;

        // overlapping checker
        if( droppingRow == colsLengths[col]) {
            initLengths(colsLengths);
            checkTetrisMap(tetrisMainMap, checkList, colsLengths);
        }

        /*if( tetrisMainMap[0][col] == '#' && tetrisMainMap[1][col] == '#') {
            printGameOverAndGTFOH();
        }*/
        
        /*// replace dropped character with a dot
        if( droppingRow < colsLengths[col] ) {
            tetrisMainMap[droppingRow++][col] = '.';
        }*/


        // (== 1) because for some reason the "if" fucks with the array and assigns some garbage values
        if( checkList[droppingRow][col] == 1){
            droppingRow = 0;
            continue;
        }
        
        // get current character from keyboard
        char chr = getch();

        // for debugging
        //usleep(100000);
        //char chr = '\000';
        // debugging budies

        // move left / right
        if(chr == 'A' || chr == 'a'){
            newCol--;
        } else if(chr == 'D' || chr == 'd'){
            newCol++;
        }

        // setting boundaries
        if( newCol >= 9 ){
            newCol = 9;
        } else if( newCol <= 0 ) {
            newCol = 0;
        }


        dropBlockOneRow(tetrisMainMap, &lShape, col, droppingRow++, newCol);
        
        col = newCol;
        /*// add the dropping chararecter
        if( droppingRow <= colsLengths[col] ) {
            tetrisMainMap[droppingRow][col] = '#';
        }*/
            

        clear();
        
        markDoneLines(checkList, completedLines, &lines);
        eliminateLines(tetrisMainMap, checkList,
         completedLines, colsLengths);
        updateTetrisMap(tetrisMainMap, checkList);
        // print current tetris map
        printMatrix(tetrisMainMap, ROWS, COLUMNS);

        //// exists for debugging
        puts("lines completed:");
        for(int col = 0; col < ROWS; col++){
                
            printf("%d ", completedLines[col]);
            
        }
        puts("\nlines lengths:");
        for(int col = 0; col < COLUMNS; col++){
                
            printf("%d ", colsLengths[col]);
            
        }
        printf("\nLine: %d", lines);
        //// debugging budies
        
    }

    return 0;

}