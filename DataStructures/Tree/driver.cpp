#include <iostream>
#include "BinaryTree.h"

int main() {
    using std::cout;
    
    /*BinaryTree<char> *T1 = new BinaryTree<char>('A');
    
    cout << "PreOrder: \n";
    T1->traversePreOrder();
    cout << "PostOrder: \n";
    T1->traversePostOrder();
    cout << "InOrder: \n";
    T1->traverseInOrder();
    cout << "LevelOrder: \n";
    T1->traverseLevelOrder();
    
    T1->insertItem('K');
    T1->traverseLevelOrder();
*/
    BinaryTree<int> *T1 = new BinaryTree<int>(1);
    for(int k = 2; k < 10; k++)
        T1->insertItem(k);
        
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