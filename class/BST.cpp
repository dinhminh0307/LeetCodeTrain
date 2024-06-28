#include "BST.h"


BST::BST() : root(nullptr) ,size(0) {}


BST::~BST() {
    destroyTree(root);
}


void BST::destroyTree(Node* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}


void BST::insert(int value) {
    insert(root, value);
}


void BST::insert(Node*& node, int value) {
    if (!node) {
            node = new Node(value);
            size++;  // Increment size when a new node is inserted
        } else if (value < node->data) {
            insert(node->left, value);
        } else if (value > node->data) {
            insert(node->right, value);
        }
}

bool BST::find(int value) {
    return find(root, value);
}




bool BST::find(Node* node, int value) {
    if (!node) {
        return false;
    } else if (value == node->data) {
        return true;
    } else if (value < node->data) {
        return find(node->left, value);
    } else {
        return find(node->right, value);
    }
}


void BST::remove(int value) {
    remove(root, value);
}


void BST::remove(Node*& node, int value) {
    if (!node) return;

        if (value < node->data) {
            remove(node->left, value);
        } else if (value > node->data) {
            remove(node->right, value);
        } else {  // Node to be deleted found
            if (!node->left) {
                Node* temp = node;
                node = node->right;
                delete temp;
            } else if (!node->right) {
                Node* temp = node;
                node = node->left;
                delete temp;
            } else {
                Node* temp = minNode(node->right);
                node->data = temp->data;
                remove(node->right, temp->data);
            }
            size--;  // Decrement size when a node is removed
        }
}


typename BST::Node* BST::minNode(Node* node) {
    while (node->left) {
        node = node->left;
    }
    return node;
}

void BST::inOrder() {
    inOrder(root);
    std::cout << std::endl;
}

void BST::inOrder(Node* node) {
    if (node) {
        inOrder(node->left);
        std::cout << node->data << " ";
        inOrder(node->right);
    }
}


// Explicit template instantiation for int type
