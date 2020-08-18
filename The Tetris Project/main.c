#include "tetrisFuncs.h"

int main() {

    char m[20][10] = {{}};

    initMatrix(m, 20, 10);

    dropOverColumn(m, 20, 10);

    return 0;

}