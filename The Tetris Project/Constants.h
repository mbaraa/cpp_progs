#ifndef CONSTANTS_H
#define CONSTANTS_H

// da boolean
#define true 1
#define false 0
typedef int bool;

// tetris' map rows and columns
const int ROWS = 20;
const int COLUMNS = 10;

// not a constant but needed globally
typedef struct {

    int height; // space taken on Y axis

    int width; // space taken on X axis

    char shape[4][2]; // 4x2

    char eqNone[4][2]; // 4x2

    int x; // X axis

    int y; // Y axis

    int rotation; // rotation * pi/2 rad

    int rotationsCounter; //


} Tetromino;




#endif //CONSTANTS_H