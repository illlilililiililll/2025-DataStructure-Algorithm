#include <stdio.h>
#include <stdlib.h>

typedef struct HashTable {
    int size;
    int* data;
};

HashTable* create(HashTable* h, int size) {
    h->size = size;
    h->data = (int*)calloc(size, sizeof(int));

    return h;
}

static int hash(const HashTable* h, int key) {
    return key % h->size;
}

void insert(HashTable* h, int key) {
    int idx = hash(h, key);
    int i = idx;

    while (h->data[idx] != 0) {
        idx = (idx + 1) % h->size;
        if (idx == i)
            return;
    }

    h->data[idx] = key;
}

int search(const HashTable* h, int key) {
    int idx = hash(h, key);
    int i = idx;

    while (h->data[idx] != 0) {
        if (h->data[idx] == key)
            return idx;
        idx = (idx + 1) % h->size;
        if (idx == i) break;
    }
    return -1;
}

void terminate(HashTable* h) {
    free(h->data);
    h->data = NULL;
    h->size = 0;
}

int main() {
    HashTable h;
    create(&h, 7);

    int a[] = {1, 2, 3, 4, 5, 6, 7};
    for (int i = 0; i < 7; i++)
        insert(&h, a[i]);

    printf("%d\n", search(&h, 5));
    printf("%d\n", search(&h, 8));

    terminate(&h);

    return 0;
}