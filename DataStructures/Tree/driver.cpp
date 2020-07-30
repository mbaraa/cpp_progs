#include <iostream>
#include "BinaryTree.h"
TEMP
void printNode(Node<type> *someNode) {

    puts("\t\t----");
    std::cout << "\t\t| " << someNode->getValue() << " |\n" ;
    puts("\t\t----");

}

int main() {
    using std::cout;
    
    BinaryTree<char> *T1 = new BinaryTree<char>('A');
    
    cout << "PreOrder: \n";
    T1->traversePreOrder();
    cout << "PostOrder: \n";
    T1->traversePostOrder();
    cout << "InOrder: \n";
    T1->traverseInOrder();

    print

    return 0;
}