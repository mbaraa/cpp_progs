#include"functions.h"
using namespace std;
int main(){
    int sudoku_eg [9][9]= { {2,8,5,7,3,6,1,9,4} , 
                            {4,7,1,9,8,2,6,3,5} ,
                            {6,3,9,5,4,1,8,2,7} ,
                            {1,9,7,6,5,4,2,8,3} ,
                            {8,5,6,3,2,9,4,7,1} ,
                            {3,2,4,1,7,8,5,6,9} ,
                            {5,4,8,2,9,7,3,1,6} ,
                            {9,1,2,4,6,3,7,5,8} ,
                            {7,6,3,8,1,5,9,4,2} };
    
    int sudoku[9][9]={ {0,0,0,0,0,0,0,0,4} , 
                        {4,0,0,0,0,0,0,0,0} ,
                        {0,0,0,0,4,0,0,0,0} ,
                        {1,0,0,0,5,0,2,0,3} ,
                        {0,0,6,0,0,9,0,0,1} ,
                        {0,2,0,1,0,0,0,0,9} ,
                        {0,4,0,0,0,0,0,1,6} ,
                        {0,0,0,0,6,0,0,0,8} ,
                        {7,0,0,0,1,0,0,0,0} };
    
    cout << "You have this sudoku map fill it properly to win!\n\n";
    print2D(sudoku);
    
    cout << "Note that you have to fill it row by row with space seperated integers including the already filled numbers\n"
            << "Tip: solve it on paper then type the answers here\n" ;
    read2D(sudoku);
    
    if ( resultRows(sudoku) && resultCols(sudoku) && resultSquares(sudoku) ){
        cout << "YAY You Won\n";
    }
    else {
        cout << "Oops you lost HAHA, Good Luck Next Time :)\n";
    }

    
    return 0;
}
