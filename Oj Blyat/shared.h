#ifndef SHARED_H
#define SHARED_H

#include <stdio.h>

void clear() {
    printf("\033[H\033[2J");
}

#endif //SHARED_H