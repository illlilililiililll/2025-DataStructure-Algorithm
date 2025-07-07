#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Simple Linked List
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head = NULL;
} LinkedList;

void insertion(LinkedList *l, int x);

int deletion(LinkedList *l, int x);

void print(const LinkedList *l);


// Circular Linked List
typedef struct CircularList {
    Node *head;
} CircularList;

void insertion(CircularList *l, int x);

int  deletion (CircularList *l, int x);

void print(const CircularList *l);


// Doubly Linked List
typedef struct DoubleNode {
    int data;
    struct DoubleNode* prev;
    struct DoubleNode* next;
} DoubleNode;

typedef struct DoubleList {
    DoubleNode *head;
} DoubleList;

void insertion(DoubleList *l, int x);

int  deletion (DoubleList *l, int x);

void print(const DoubleList *l);

#endif
