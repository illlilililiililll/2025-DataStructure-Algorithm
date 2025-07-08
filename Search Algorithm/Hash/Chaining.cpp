#include <stdio.h>
#include <stdlib.h>
#include "../../Linear DataStructures/Linked List/Linked List.h"

typedef struct HashTable {
    int size;
    LinkedList** cells;
} HashTable;

HashTable* create(HashTable* h, int size) {
    h->size = size;
    h->cells = (LinkedList**)malloc(size * sizeof(LinkedList*));

    for (int i = 0; i < size; i++) {
        h->cells[i] = (LinkedList*)malloc(sizeof(LinkedList));
        h->cells[i]->head = NULL;
    }

    return h;
}

static int hash(const HashTable* h, int key) {
    return key % h->size;
}

// Check if key exists in the linked list
static int contains(LinkedList* l, int key) {
    Node* curr = l->head;
    while (curr) {
        if (curr->data == key)
            return 1;
        curr = curr->next;
    }
    return 0;
}

void insert(HashTable* h, int key) {
    int idx = hash(h, key);
    LinkedList* l = h->cells[idx];
    if (!contains(l, key)) {
        insertion(l, key);
    }
}

int search(const HashTable* h, int key) {
    int idx = hash(h, key);
    if (contains(h->cells[idx], key))
        return idx;
    return -1;
}

void terminate(HashTable* h) {
    for (int i = 0; i < h->size; i++) {
        Node* curr = h->cells[i]->head;
        while (curr) {
            Node* tmp = curr;
            curr = curr->next;
            free(tmp);
        }
        free(h->cells[i]);
    }
    free(h->cells);
    h->cells = NULL;
    h->size = 0;
}

int main() {
    HashTable h;
    create(&h, 7);

    int keys[] = {1,2,3,4,5,6,7};
    for (int i = 0; i < 7; i++) {
        insert(&h, keys[i]);
    }

    printf("%d\n", search(&h, 5));
    printf("%d\n", search(&h, 8));

    terminate(&h);
    return 0;
}
