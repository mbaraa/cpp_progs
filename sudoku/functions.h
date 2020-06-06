#include <stdio.h>


// super slavic read matrix function
void read2DfromSTDIN(void *matrixPtr){
    // matrixPtr is a pointer to the 2d array
    // assigning a new array with the location of the given array
    int (*matrix)[9] = matrixPtr;

    // row & column counters for the array
    size_t row, column;
    for(row = 0; row < 9; row++){
        for(column = 0; column < 9; column++){
            scanf("%d", &matrix[row][column]);
        }
    }
    
}

void read2DfromFile(void *matrixPtr){
    // matrixPtr is a pointer to the 2d array
    // assigning a new array with the location of the given array
    int (*matrix)[9] = matrixPtr;

    FILE *sudokuMap;
    sudokuMap = fopen("map.txt", "r");
    int temp[9*9];
    int counter = 0;
    while(!feof(sudokuMap)){
        int element;
        //fscanf(sudokuMap, "%d", element);
        element = (fgetc(sudokuMap) - 48);
        if(element >= 0){
            //printf("%c", fgetc(sudokuMap));
            temp[counter] = element;
            counter++;
        }
        
        
    }
    fclose(sudokuMap);
    
    // row & column counters for the array
    size_t row, column;
    for(row = 0; row < 9; row++){
        for(column = 0; column < 9; column++){
            matrix[row][column] = temp[row*9 + column];
        }
    }
    
}
void print2D(int *matrixPtr){
    // matrixPtr is a pointer to the 2d array
    // assigning a new array with the location of the given array
    int (*matrix)[9] = matrixPtr;

    // row & column counters for the array
    size_t row, column;
    for ( row = 0 ; row < 9 ; row++ ){
        for ( column = 0 ; column < 9 ; column++){
            char *seperator = (column == 8 ? "" : " | ");
            printf("%d%s", matrix[row][column], seperator);
        }
        puts("\n----------------------------------");
    }
}
// frequency array
int freq[10]={};

int resultRows( int *sudokuPtr ){
    int (*sudoku)[9] = sudokuPtr;
    for ( int lol = 0 ; lol < 9 ; lol++ ){
        for ( int lol2 = 0 ;lol2 < 9 ; lol2++){
            freq[ sudoku[lol][lol2] ]++;

            if ( freq[ sudoku[lol][lol2] ] > 1 ){
                return 0;
            }
        }
        //this resets the frequency array
        for ( int k = 0 ; k < 10 ; k++ ){
            freq[k] = 0;
        }
    }
    return 1;
}

int resultCols( int *sudokuPtr ){
    int (*sudoku)[9] = sudokuPtr;
    for ( int lol = 0 ; lol < 9 ; lol++ ){
        for ( int lol2 = 0 ;lol2 < 9 ; lol2++){
            freq[ sudoku[lol2][lol] ]++;

            if ( freq[ sudoku[lol2][lol] ] > 1 ){
                return 0;
            }
        }
        //this resets the frequency array
        for ( int k = 0 ; k < 10 ; k++ ){
            freq[k] = 0;
        }
    }
    return 1;
}
// I wanted to leave a comment but I don't want to....
int resultSquares( int *sudokuPtr ){
    int (*sudoku)[9] = sudokuPtr;
    for ( int rows = 0 ; rows < 9 ; rows+=3 ){
        for ( int cols = 0 ;cols < 9 ; cols+=3){
            for ( int lol = 0 ; lol < 3 ; lol++ ){
                for ( int lol2 = 0 ; lol2 < 3 ; lol2++ ){

                        freq[ sudoku[lol+rows][lol2+cols] ]++;

                        if ( freq[ sudoku[lol+rows][lol2+cols] ] > 1 ){
                            return 0;
                        }
                }

                        //this resets the frequency array
                        for ( int k = 0 ; k < 10 ; k++ ){
                                freq[k] = 0;
                        }
            }
        }
    }
    return 1;
}

void checkSolution(int *solutionPtr){
    int (*solution)[9] = solutionPtr;

    if ( resultRows(solution) && resultCols(solution) && resultSquares(solution) ){
        puts("\nYou Won YAY!\n");
        puts("Hers's your solution for screenshot purposes:\n");
        print2D(solution);
    }
    else {
        puts("HAHA you lost, better Luck Next Time(if exists)");
        puts("\nHere's your worthless solution:\n");
        print2D(solution);
    }
}