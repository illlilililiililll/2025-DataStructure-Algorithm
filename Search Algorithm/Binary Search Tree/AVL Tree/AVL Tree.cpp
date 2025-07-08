#include <stdio.h>
#include <stdlib.h>
#include "AVL Tree.h"

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node* root) {
    if (root == NULL)
        return 0;
    return root->height;
}

int getBalance(Node* root) {
    if (root == NULL)
        return 0;

    return height(root->left) - height(root->right);
}

Node* minNode(Node* root) {
    Node* temp = root;

    while (temp->left != NULL)
        temp = temp->left;

    return temp;
}

Node* RR(Node* root) {
    Node* child = root->left;
    Node* temp = child->right;

    child->right = root;
    root->left = temp;

    root->height = max(height(root->left), height(root->right)) + 1;
    child->height = max(height(child->left), height(child->right)) + 1;

    return child;
}

Node* LL(Node* root) {
    Node* child = root->right;
    Node* temp = child->left;

    child->left = root;
    root->right = temp;

    root->height = max(height(root->left), height(root->right)) + 1;
    child->height = max(height(child->left), height(child->right)) + 1;

    return child;
}

Node* insert(Node* root, int key) {
    if (root == NULL) {
        Node* node = (Node*)malloc(sizeof(Node));

        node->key = key;
        node->left = NULL;
        node->right = NULL;
        node->height = 1;

        return node;
    }

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && key < root->left->key)
        return RR(root);

    if (balance < -1 && key > root->right->key)
        return LL(root);

    if (balance > 1 && key > root->left->key) {
        root->left = LL(root->left);
        return RR(root);
    }

    if (balance < -1 && key < root->right->key) {
        root->right = RR(root->right);
        return LL(root);
    }

    return root;
}

Node* deleteNode(Node *root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            Node *temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            Node *temp = minNode(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
        return RR(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = LL(root->left);
        return RR(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return LL(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = RR(root->right);
        return LL(root);
    }

    return root;
}

Node* search(Node* root, int target) {
    if (root == NULL || root->key == target)
        return root;

    if (root->key < target)
        return search(root->right, target);
    else
        return search(root->left, target);
}

void LVR(const Node* root) {
    if (root == NULL) return;

    LVR(root->left);
    printf("%d ", root->key);
    LVR(root->right);
}