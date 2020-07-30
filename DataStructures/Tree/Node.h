#define TEMP template<typename type>

TEMP
class Node {
public:
    // constructor
    Node<type>(type);

    // setters & getters
    Node<type> setParent(Node<type> *);
    Node<type> *getParent();
    
    Node<type> setLeft(Node<type> *);
    Node<type> *getLeft();
    
    Node<type> setRight(Node<type> *);
    Node<type> *getRight();
    
    Node<type> setSibling(Node<type> *);
    Node<type> *getSibling();
    
    Node<type> setValue(type);
    type getValue();

    // check capacity
    bool isFull();
    bool isEmpty();

private:
    type value;
    Node<type> *parent;
    Node<type> *leftChild;
    Node<type> *rightChild;
    Node<type> *rightSibling;

};

TEMP
// constructor
Node<type>::Node(type value) {
    this->value = value;
}

TEMP
// set left child
Node<type> Node<type>::setLeft(Node<type> *left) {
    this->leftChild = left;

    return *this;
}
TEMP
// get left child
Node<type> *Node<type>::getLeft() {
    return this->leftChild;
}

TEMP
// set right child
Node<type> Node<type>::setRight(Node<type> *right) {
    this->rightChild = right;

    return *this;
}
TEMP
// get right child
Node<type> *Node<type>::getRight() {
    return this->rightChild;
}

TEMP
// set parent
Node<type> Node<type>::setParent(Node<type> *parent) {
    this->parent = parent;

    return *this;
}
TEMP
// get parent
Node<type> *Node<type>::getParent() {
    return this->parent;
}

TEMP
// set right sibling
Node<type> Node<type>::setSibling(Node<type> *sibling) {
    this->rightSibling = sibling;

    return *this;
}
TEMP
// get right sibling
Node<type> *Node<type>::getSibling() {
    return this->rightSibling;
}

TEMP
// set value
Node<type> Node<type>::setValue(type value) {
    this->value = value;

    return *this;
}
TEMP
// get value
type Node<type>::getValue() {
    return this->value;
}

TEMP
// check if the node is empty
bool Node<type>::isEmpty() {
    return (!leftChild && !rightChild);
}

TEMP
// check if the node is full
bool Node<type>::isFull() {
    return (leftChild && rightChild);
}