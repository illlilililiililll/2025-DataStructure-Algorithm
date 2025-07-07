#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void init(Deque *q, int max) {
    q->max = max;
    q->ptr = q->front = q->rear = 0;
    q->data = (int*)calloc(max, sizeof(int));
}

bool empty(const Deque *q) {
    return q->ptr == 0;
}

void append_front(Deque *q, int x) {
    q->ptr++;

    if (--q->front == -1)
        q->front = q->max - 1;

    q->data[q->front] = x;
}

void append_rear(Deque *q, int x) {
    q->ptr++;
    q->data[q->rear++] = x;

    if (q->rear == q->max)
        q->rear = 0;
}

int delete_front(Deque *q) {
    q->ptr--;
    int result = q->data[q->front++];
    if (q->front == q->max)
        q->front = 0;

    return result;
}

int delete_rear(Deque *q) {
    q->ptr--;

    if (--q->rear == -1)
        q->rear = q->max - 1;

    return q->data[q->rear];
}

void clear(Deque *q) {
    q->ptr = q->front = q->rear = 0;
}

int capacity(const Deque *q) {
    return q->max;
}

int size(const Deque *q) {
    return q->ptr;
}

int search(const Deque *q, int x) {
    for (int i = 0; i < q->ptr; i++) {
        int idx = (i + q->front) % q->max;
        if (q->data[idx] == x)
            return i;
    }
    return -1;
}

void printDeque(const Deque *q) {
    printf("{ ");
    for (int i = 0; i < q->ptr; i++) {
        printf("%d", q->data[(i + q->front) % q->max]);
        if (i < q->ptr - 1) {
            printf(", ");
        }
    }
    printf(" }\n");
}

void terminate(Deque *q) {
    free(q->data);
    q->max = q->front = q->rear = 0;
}