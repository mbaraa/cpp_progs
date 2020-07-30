#include <iostream>
#include "BinaryTree.h"

int main() {
    using std::cout;
    
    BinaryTree<char> *T1 = new BinaryTree<char>('A');
    
    cout << "PreOrder: \n";
    T1->traversePreOrder();
    cout << "PostOrder: \n";
    T1->traversePostOrder();
    cout << "InOrder: \n";
    T1->traverseInOrder();
    cout << "LevelOrder: \n";
    T1->traverseLevelOrder();
    

    return 0;
}