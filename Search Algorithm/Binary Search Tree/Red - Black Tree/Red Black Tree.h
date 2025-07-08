#ifndef RBTREE_H
#define RBTREE_H

typedef enum { RED, BLACK } Color;

typedef struct Node {
    int key;
    Color color;
    Node* parent;
    Node* left;
    Node* right;
} Node;

typedef struct {
    Node* root;
    Node* nil;
} Tree;

#endif