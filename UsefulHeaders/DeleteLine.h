#ifndef DELETELINE_H
#define DELETELINE_H 1

#include <stdio.h>

// delete a line from stdout
void deleteLine() {
    printf("\033[F"); // "\033[F" moves cursor to the beginning of the previous line
                      // also there's "\033[A" – move cursor up one line
    printf("\n");
    
}

// delete the previous line from stdout
void deletePreviousLine() {
    printf("\033[F");
    printf("\033[F"); // "\033[F" moves cursor to the beginning of the previous line
                      // also there's "\033[A" – move cursor up one line
    printf("\n");

}

#endif //DELETELINE_H