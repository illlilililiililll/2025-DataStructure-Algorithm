#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

// ArrayQueue
void init(arrayQueue *q, int max) {
    q->max = max;
    q->ptr = 0;
    q->data = (int*)calloc(max, sizeof(int));
}

bool empty(const arrayQueue *q) {
    return q->ptr == 0;
}

void enqueue(arrayQueue *q, int x) {
    q->data[q->ptr++] = x;
}

int dequeue(arrayQueue *q) {
    int result = q->data[0];
    for (int i = 1; i < q->ptr; i++)
        q->data[i - 1] = q->data[i];
    q->ptr--;

    return result;
}

int peek(const arrayQueue *q) {
    return q->data[0];
}

void clear(arrayQueue *q) {
    q->ptr = 0;
}

int capacity(const arrayQueue *q) {
    return q->max;
}

int size(const arrayQueue *q) {
    return q->ptr;
}

int search(const arrayQueue *q, int x) {
    for (int i = 0; i < q->ptr; i++)
        if (q->data[i] == x)
            return i;

    return -1;
}

void printQueue(const arrayQueue *q) {
    printf("{ ");
    for (int i = 0; i < q->ptr; i++) {
        printf("%d", q->data[i]);
        if (i < q->ptr - 1) {
            printf(", ");
        }
    }
    printf(" }\n");
}

void terminate(arrayQueue *q) {
    free(q->data);
    q->max = q->ptr = 0;
}

// CircularQueue
void init(Deque *q, int max) {
    q->max = max;
    q->ptr = q->front = q->rear = 0;
    q->data = (int*)calloc(max, sizeof(int));
}

bool empty(const Deque *q) {
    return q->ptr == 0;
}

void enqueue(Deque *q, int x) {
    q->ptr++;
    q->data[q->rear++] = x;

    if (q->rear == q->max)
        q->rear = 0;
}

int dequeue(Deque *q) {
    q->ptr--;
    int result = q->data[q->front++];
    if (q->front == q->max)
        q->front = 0;

    return result;
}

int peek(const Deque *q) {
    return q->data[q->front];
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

void printQueue(const Deque *q) {
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