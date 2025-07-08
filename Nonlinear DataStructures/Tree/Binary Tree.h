#ifndef BINARYTREE_H
#define BINARYTREE_H

typedef struct Node {
    int data;
    Node* left;
    Node* right;
} Node;

Node* createNode(int value);

Node* insertRight(Node* root, int value);

Node* insertLeft(Node* root, int value);

void VLR(Node* root);

void LVR(Node* root);

void LRV(Node* root);

#endif