#include "tetrisFuncs.h"
#include "Constants.h"

int main() {


    char tetrisMainMap[ROWS][COLUMNS];
    // mark each taken place with true(1)
    bool checkList[ROWS][COLUMNS];
    // columns lengths
    int colsLengths[COLUMNS];
    // completed rows
    bool completedLines[ROWS];

    initLengths(colsLengths);
    initCheckList(checkList);
    initTetrisMap(tetrisMainMap);
    initCompletedLines(completedLines);

    //dropOverColumn(m, 20, 10);

    // start dropping from the first row
    int droppingRow = -1;
    // dropping starts from the middle
    int col = COLUMNS / 2;
    
    // print current tetris
    printMatrix(tetrisMainMap, ROWS, COLUMNS);

    while( true ) {

        // overlapping checker
        if( droppingRow == colsLengths[col]) {
            checkTetrisMap(tetrisMainMap, checkList, colsLengths);
        }

        if( tetrisMainMap[0][col] == '#' && tetrisMainMap[1][col] == '#') {
            for(int col = 0; col < ROWS; col++){
                
                printf("%d ", completedLines[col]);
            
           }
            printGameOverAndGTFOH();
        }
        
        // replace dropped character with a dot
        if( droppingRow <= colsLengths[col] ) {
            tetrisMainMap[droppingRow++][col] = '.';
        }
        // (== 1) because for some reason the "if" fucks with the array and assigns some garbage values
        if( checkList[droppingRow][col] == 1){
            droppingRow = 0;
            continue;
        }
        
        // get current character from keyboard
        char chr = getch();

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

        // add the dropping chararecter
        if( droppingRow <= colsLengths[col] + 1) {
            tetrisMainMap[droppingRow][col] = '#';
        }
            

        clear();
        
        markDoneLines(checkList, completedLines);
        eliminateLines(tetrisMainMap, checkList, completedLines);
        updateTetrisMap(tetrisMainMap, checkList);
        // print current tetris map
        printMatrix(tetrisMainMap, ROWS, COLUMNS);

        
    }

    return 0;

}