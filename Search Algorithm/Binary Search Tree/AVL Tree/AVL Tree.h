#ifndef AVL_H
#define AVL_H

typedef struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
} Node;

Node* insert(Node *root, int key);

Node* deleteNode(Node *root, int key);

Node* search(Node *root, int key);

int   height(Node* root);

int   getBalance(Node *root);

Node* LL(Node* root);

Node* RR(Node* root );

#endif