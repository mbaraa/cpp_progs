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
    
    Node<type> setValue(type);
    type getValue();


private:
    type value;
    Node<type> *parent;
    Node<type> *leftChild;
    Node<type> *rightChild;

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