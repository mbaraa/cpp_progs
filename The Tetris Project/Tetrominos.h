#ifndef TETROMINOS_H
#define TETROMINOS_H

#include "Constants.h"

Tetromino square = {
    // height
    2,
    // width
    2, 
    // shape
    { {'#', '#'}, 
      {'#', '#'},
      {'\0', '\0'},
      {'\0', '\0'}},
    // eqNone
    { {'.', '.'}, 
      {'.', '.'},
      {'\0', '\0'},
      {'\0', '\0'}},
    // x
    4,
    // y
    0,
    // rotation
    0
                
};

Tetromino straight = {
    // height
    4,
    // width
    1, 
    // shape
    { {'#', '\0'}, 
      {'#', '\0'},
      {'#', '\0'},
      {'#', '\0'}},
    // eqNone
    { {'.', '\0'}, 
      {'.', '\0'},
      {'.', '\0'},
      {'.', '\0'}},
    // x
    4,
    // y
    0,
    // rotation
    0
                
};

Tetromino lShape = {
    // height
    3,
    // width
    2, 
    // shape
    { {'#', '.'}, 
      {'#', '.'},
      {'#', '#'},
      {'\0', '\0'}},
    // eqNone
    { {'.', '.'}, 
      {'.', '.'},
      {'.', '.'},
      {'\0', '\0'}},
    // x
    4,
    // y
    0,
    // rotation
    0
                
};

Tetromino lShapeInverse = {
    // height
    3,
    // width
    2, 
    // shape
    { {'.', '#'}, 
      {'.', '#'},
      {'#', '#'},
      {'\0', '\0'}},
    // eqNone
    { {'.', '.'}, 
      {'.', '.'},
      {'.', '.'},
      {'\0', '\0'}},
    // x
    4,
    // y
    0,
    // rotation
    0
                
};

Tetromino tShape = {
    // height
    3,
    // width
    2, 
    // shape
    { {'#', '.'}, 
      {'#', '#'},
      {'#', '.'},
      {'\0', '\0'}},
    // eqNone
    { {'.', '.'}, 
      {'.', '.'},
      {'.', '.'},
      {'\0', '\0'}},
    // x
    4,
    // y
    0,
    // rotation
    3
                
};

Tetromino skew = {
    // height
    3,
    // width
    2, 
    // shape
    { {'.', '#'}, 
      {'#', '#'},
      {'#', '.'},
      {'\0', '\0'}},
    // eqNone
    { {'.', '.'}, 
      {'.', '.'},
      {'.', '.'},
      {'\0', '\0'}},
    // x
    4,
    // y
    0,
    // rotation
    0
                
};

Tetromino skewInverse = {
    // height
    3,
    // width
    2, 
    // shape
    { {'#', '.'}, 
      {'#', '#'},
      {'.', '#'},
      {'\0', '\0'}},
    // eqNone
    { {'.', '.'}, 
      {'.', '.'},
      {'.', '.'},
      {'\0', '\0'}},
    // x
    4,
    // y
    0,
    // rotation
    0
                
};

#endif // TETROMINOS_H