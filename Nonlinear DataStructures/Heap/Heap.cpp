#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

void init(heap *h) {
    h->size = 0;
    h->data = (int*)malloc(2*sizeof(int));
}

void insert(heap *h, int x) {
    int i = ++(h->size);
    h->data = (int*)realloc(h->data, h->size*sizeof(int));

    while ((i != 1) && (x > h->data[i / 2])) {
        h->data[i] = h->data[i / 2];
        i /= 2;
    }
    h->data[i] = x;
}

int remove(heap *h) {
    int parent, child;
    int x, temp;

    x = h->data[1];
    temp = h->data[(h->size)--];
    parent = 1;
    child = 2;

    while (child <= h->size) {
        if ((child < h->size) && (h->data[child] < h->data[child + 1]))
            child++;
        if (temp >= h->data[child]) break;

        h->data[parent] = h->data[child];
        parent = child;
        child *= 2;
    }
    h->data[parent] = temp;
    return x;
}

void printHeap(heap *h) {
    for (int i = 1; i <= h->size; i++) {
        printf("%d ", h->data[i]);
    }
    printf("\n");
}

void terminate(heap *h) {
    free(h->data);
}
