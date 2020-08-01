#ifndef DELETELINE_H
#define DELETELINE_H 1

#include <stdio.h>

// delete a line from stdout
void deleteLine() {
    // to delete the current line
    printf("\033[F"); // "\033[F" moves cursor to the beginning of the previous line
                      // also there's "\033[A" – move cursor up one line
    printf("\n");
    
}

// delete the previous line from stdout
void deletePreviousLine() {
    // to jump to the previous line
    printf("\033[F");
    // to delete the previous line
    printf("\033[F"); // "\033[F" moves cursor to the beginning of the previous line
                      // also there's "\033[A" – move cursor up one line
    printf("\n");

}

// delete the previous n lines from stdout
void deletePreviousNLines(int numberOfLines) {
    // to jump to the previous line
    printf("\033[F");
    // delete n lines 
    while(numberOfLines--){
        printf("\033[F");
    }
    
    printf("\n");

}
#endif //DELETELINE_H