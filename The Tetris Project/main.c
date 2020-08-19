#include "tetrisFuncs.h"
#include "Constants.h"

int main() {


    char tetrisMainMap[ROWS][COLUMNS];
    // mark each taken place with true(1)
    bool checkList[ROWS][COLUMNS];
    // columns lengths
    int colsLengths[COLUMNS];//

    initLengths(colsLengths);
    initCheckList(checkList);
    initTetrisMap(*tetrisMainMap, ROWS, COLUMNS);

    //dropOverColumn(m, 20, 10);

    // start dropping from the first row
    int droppingRow = -1;
    // dropping starts from the middle
    int col = COLUMNS / 2;
    // print current tetris
    printMatrix(*tetrisMainMap, ROWS, COLUMNS);

    while( true ) {

        // overlapping checker
        if( droppingRow == colsLengths[col]) {
            checkTetrisMap(*tetrisMainMap, *checkList, ROWS, COLUMNS, colsLengths);
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
        if( droppingRow <= colsLengths[col] ) {
            tetrisMainMap[droppingRow][col] = '#';
        }
            

        clear();
        
        updateTetrisMap(*tetrisMainMap, *checkList, ROWS, COLUMNS);
        // print current tetris map
        printMatrix(*tetrisMainMap, ROWS, COLUMNS);

        
    }

    return 0;

}