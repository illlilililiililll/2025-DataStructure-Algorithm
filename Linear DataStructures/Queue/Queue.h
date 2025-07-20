#ifndef QUEUE_H
#define QUEUE_H

// ArrayQueue
typedef struct arrayQueue {
    int max;
    int ptr;
    int *data;
} arrayQueue;

void init(arrayQueue *q, int max);

bool empty(const arrayQueue *q);

void enqueue(arrayQueue *q, int x);

int dequeue(arrayQueue *q);

int peek(const arrayQueue *q);

void clear(arrayQueue *q);

int capacity(const arrayQueue *q);

int size(const arrayQueue *q);

int search(const arrayQueue *q, int x);

void printQueue(const arrayQueue *q);

void terminate(arrayQueue *q);

// CircularQueue
typedef struct Queue {
    int max;
    int ptr;
    int front;
    int rear;
    int *data;
} circularQueue;

void init(circularQueue *q, int max);

bool empty(const circularQueue *q);

void enqueue(circularQueue *q, int x);

int dequeue(circularQueue *q);

int peek(const circularQueue *q);

void clear(circularQueue *q);

int capacity(const circularQueue *q);

int size(const circularQueue *q);

int search(const circularQueue *q, int x);

void printQueue(const circularQueue *q);

void terminate(circularQueue *q);

#endif