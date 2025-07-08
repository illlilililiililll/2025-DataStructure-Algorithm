#include <stdio.h>
#include <stdlib.h>
#include "Binary Tree.h"

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node* insertRight(Node* root, int value) {
    root->right = createNode(value);

    return root->right;
}

Node* insertLeft(Node* root, int value) {
    root->left = createNode(value);

    return root->left;
}

void VLR(Node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    VLR(root->left);
    VLR(root->right);
}

void LVR(Node* root) {
    if (root == NULL) return;

    LVR(root->left);
    printf("%d ", root->data);
    LVR(root->right);
}

void LRV(Node* root) {
    if (root == NULL) return;
    LRV(root->left);
    LRV(root->right);
    printf("%d ", root->data);
}