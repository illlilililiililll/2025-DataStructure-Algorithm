#include <stdio.h>
#include <stdlib.h>
#include "Binary Search Tree.h"

Node* searchNode(Node* root, int target) {
    if (root == NULL || root->value == target)
        return root;

    if (root->value < target)
        return searchNode(root->right, target);
    else
        return searchNode(root->left, target);
}

Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        root = (Node*)malloc(sizeof(Node));

        root->value = value;
        root->left = root->right = NULL;

        return root;
    }

    if (value < root->value)
        root->left = insertNode(root->left, value);
    else if (value > root->value)
        root->right = insertNode(root->right, value);

    return root;
}

Node* findMin(Node* root) {
    Node* temp = root;

    while (temp->left != NULL)
        temp = temp->left;

    return temp;
}

Node* deleteNode(Node* root, int value) {
    Node* target = NULL;

    if (root == NULL)
        return NULL;

    if (value > root->value)
        root->right = deleteNode(root->right, value);
    else if (value < root->value)
        root->left = deleteNode(root->left, value);
    else
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL || root->right == NULL) {
            Node *temp;

            if (root->left == NULL)
                temp = root->right;
            else
                temp = root->left;

            free(root);
            return temp;
        } else {
            Node *temp = findMin(root->right);

            root->value = temp->value;
            root->right = deleteNode(root->right, temp->value);
        }

    return root;
}

void VLR(const Node* root) {
    if (root == NULL) return;

    printf("%d ", root->value);
    VLR(root->left);
    VLR(root->right);
}

void LVR(const Node* root) {
    if (root == NULL) return;

    LVR(root->left);
    printf("%d ", root->value);
    LVR(root->right);
}

void LRV(const Node* root) {
    if (root == NULL) return;

    LRV(root->left);
    LRV(root->right);
    printf("%d ", root->value);
}