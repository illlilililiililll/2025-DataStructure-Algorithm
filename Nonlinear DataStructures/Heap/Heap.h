#ifndef HEAP_H
#define HEAP_H

typedef struct heap {
    int size;
    int *data;
} heap;

void init(heap *h);
void insert(heap *h, int x);
int remove(heap *h);
void printHeap(heap *h);
void terminate(heap *h);

#endif