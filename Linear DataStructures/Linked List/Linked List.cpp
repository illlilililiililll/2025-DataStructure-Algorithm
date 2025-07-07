#include <stdio.h>
#include <stdlib.h>
#include "Linked List.h"

// Simply Linked List
void insertion(LinkedList *l, int x) {
    Node* node = (Node*)malloc(sizeof *node);
    node->data = x;
    node->next = NULL;

    if (l->head == NULL) {
        l->head = node;
        return;
    }

    Node *current = l->head;
    while (current->next != NULL)
        current = current->next;

    current->next = node;
}

int deletion(LinkedList *l, int x) {
    Node *current = l->head;
    Node *prev    = NULL;

    /* 1) x를 포함한 노드 탐색 */
    while (current && current->data != x) {
        prev    = current;
        current = current->next;
    }
    if (current == NULL)
        return -1;

    if (prev == NULL)
        l->head = current->next;
    else
        prev->next = current->next;

    int removed = current->data;
    free(current);

    return removed;
}

void print(const LinkedList *l) {
    printf("{ ");
    Node *current = l->head;

    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("}");
}


// Circular Linked List
void insertion(CircularList *l, int x)
{
    Node *node = (Node *)malloc(sizeof *node);
    node->data = x;

    if (l->head == NULL) {
        node->next = node;
        l->head    = node;
        return;
    }

    Node *tail = l->head;
    while (tail->next != l->head)
        tail = tail->next;

    tail->next  = node;
    node->next  = l->head;
}

int deletion(CircularList *l, int x)
{
    if (l->head == NULL)
        return -1;

    Node *current  = l->head;
    Node *prev = NULL;

    do {
        if (current->data == x) {
            if (prev) prev->next = current->next;
            else {
                if (current->next == current) {
                    l->head = NULL;
                } else {
                    Node *tail = current;
                    while (tail->next != l->head)
                        tail = tail->next;
                    l->head   = current->next;
                    tail->next = l->head;
                }
            }
            int value = current->data;
            free(current);
            return value;
        }
        prev = current;
        current  = current->next;
    } while (current != l->head);

    return -1;
}

void print(const CircularList *l)
{
    printf("{ ");
    if (l->head) {
        const Node *current = l->head;
        do {
            printf("%d ", current->data);
            current = current->next;
        } while (current != l->head);
    }
    printf("}");
}

// Doubly Linked List
void insertion(DoubleList *l, int x)
{
    DoubleNode *node = (DoubleNode *)malloc(sizeof *node);
    node->data = x;
    node->next = NULL;
    node->prev = NULL;

    if (l->head == NULL) {
        l->head = node;
        return;
    }

    DoubleNode *tail = l->head;
    while (tail->next)
        tail = tail->next;

    tail->next = node;
    node->prev = tail;
}

int deletion(DoubleList *l, int x)
{
    DoubleNode *current = l->head;
    while (current && current->data != x)
        current = current->next;

    if (current == NULL)
        return -1;

    if (current->prev) current->prev->next = current->next;
    else l->head = current->next;

    if (current->next) current->next->prev = current->prev;

    int value = current->data;
    free(current);
    return value;
}

void print(const DoubleList *l)
{
    const DoubleNode *current = l->head;
    printf("{ ");
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("}");
}

