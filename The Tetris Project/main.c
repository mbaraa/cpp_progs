#include "tetrisFuncs.h"
#include "Constants.h"
#include "Tetrominos.h"

int main() {

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


    int newCol = col;


    Tetromino tetrominos[] = {square, straight,
                         lShape, lShapeInverse,
                         tShape, skew, skewInverse};
    
    int counter = 0;
        
    Tetromino *block;
    //block = &tetrominos[counter];
        
    block = &skew;
    block->x = 4;
    block->y = 0;

    while( true ) {


        block->y = droppingRow - (block->height - 1); // height - 1 
        
        
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
            if(counter >= 6) {
            counter = 0;
        }
        else {
            counter++;
        }
            droppingRow = 0;
            continue;
        }
        
        // get current character from keyboard
        char chr = '\0'; 
        getch();

        // for debugging
        //usleep(100000);
        //char chr = '\000';
        // debugging budies

        // move left / right
        if(chr == 'A' || chr == 'a') {
            newCol--;
        } 
        else if(chr == 'D' || chr == 'd') {
            newCol++;
        } 
        else if(chr == 'W' || chr == 'w') {
            if(block->rotation >= 3) {
                block->rotation = 0;
                block->rotationsCounter = 0;
            }
            else {
                block->rotation++;
            }
        }

        // setting boundaries
        if( newCol >= 9 ){
            newCol = 9;
        } else if( newCol <= 0 ) {
            newCol = 0;
        }



        dropBlockOneRow(tetrisMainMap, block, col, droppingRow++, newCol);
        

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

        printf("%d %d\n", droppingRow, colsLengths[col]);

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