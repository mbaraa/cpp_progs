#include "tetrisFuncs.h"


int main() {
    int rows = 20;
    int columns = 10;

    char tetrisMainMap[rows][columns];
    // mark each taken place with true(1)
    bool checkList[rows][columns];
    // columns lengths
    int colsLengths[columns];//

    initLengths(colsLengths);
    initCheckList(checkList);
    initMatrix(*tetrisMainMap, rows, columns);

    //dropOverColumn(m, 20, 10);

    // start dropping from the first row
    int droppingRow = -1;
    // dropping starts from the middle
    int col = columns / 2;
    // print current tetris
    printMatrix(*tetrisMainMap, rows, columns);
    
/*    for(int i = 0; i < 10; i++) {
        printf("%d ", colsLengths[i]);

    }
*/
    while( true ) {//droppingRow < rows - 1 ) {

        // overlapping checker
        if( droppingRow == colsLengths[col]) {
            checkMap(*tetrisMainMap, *checkList, rows, columns, colsLengths);
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
        
        updateTetrisMap(*tetrisMainMap, *checkList, rows, columns);
        // print current tetris map
        printMatrix(*tetrisMainMap, rows, columns);

        
    }

    return 0;

}