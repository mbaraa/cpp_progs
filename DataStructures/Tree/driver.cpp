#include <iostream>
#include "BinaryTree.h"

int main() {
    BinaryTree<char> *T1 = new BinaryTree<char>('A');
    T1->traversePreOrder();


    return 0;
}