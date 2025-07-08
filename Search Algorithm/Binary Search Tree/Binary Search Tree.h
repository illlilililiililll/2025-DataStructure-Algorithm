#ifndef BST_H
#define BST_H

typedef struct Node {
    int   value;
    struct Node* left;
    struct Node* right;
} Node;

Node* searchNode(Node* root, int target);

Node* insertNode(Node* root, int value);

Node* deleteNode(Node* root, int value);

void VLR(const Node* root);

void LVR(const Node* root);

void LRV(const Node* root);

#endif