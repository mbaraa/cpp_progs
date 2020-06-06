#include <stdio.h>
#include "functions.h"

int main(){
    int sudoku[9][9] ={ {0,0,0,0,0,0,0,0,4} ,
                        {4,0,0,0,0,0,0,0,0} ,
                        {0,0,0,0,4,0,0,0,0} ,
                        {1,0,0,0,5,0,2,0,3} ,
                        {0,0,6,0,0,9,0,0,1} ,
                        {0,2,0,1,0,0,0,0,9} ,
                        {0,4,0,0,0,0,0,1,6} ,
                        {0,0,0,0,6,0,0,0,8} ,
                        {7,0,0,0,1,0,0,0,0} };

    puts ("You have this sudoku map fill it properly to win!\n");
    print2D(sudoku);

//    puts("Note that you have to fill it row by row with space seperated integers including the already filled numbers");
    puts("\nTip: solve it on paper then type the answers here\n");
    
    read2DfromFile(sudoku);
    checkSolution(sudoku);

    return 0;
}
