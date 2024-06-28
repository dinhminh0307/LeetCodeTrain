#include <iostream>

#ifndef BST_H
#define BST_H

class BST {
public:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node* parent;
        Node(int val) : data(val), left(nullptr), right(nullptr), parent(nullptr) {}

    };

    BST();                    // Constructor
    ~BST();                   // Destructor
    void insert(int value);     // Insert value into BST
    bool find(int value);       // Find value in BST
    void remove(int value);     // Remove value from BST
    void inOrder();           // In-order traversal
    
    
private:
    int size;
    Node* root;
    Node* getRoot();
    void insert(Node*& node, int value);
    bool find(Node* node, int value);
    void remove(Node*& node, int value);
    Node* minNode(Node* node);
    void inOrder(Node* node);
    void destroyTree(Node* node);
    void  printFullTree();
};

#endif
