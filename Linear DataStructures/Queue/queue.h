#ifndef QUEUE_H
#define QUEUE_H

// ArrayQueue
typedef struct arrayQueue {
    int max;
    int ptr;
    int *data;
} arrayQueue;

void init(arrayQueue *Deque, int max);

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
typedef struct Deque {
    int max;
    int ptr;
    int front;
    int rear;
    int *data;
} circularQueue;

void init(Deque *Deque, int max);

bool empty(const Deque *q);

void enqueue(Deque *q, int x);

int dequeue(Deque *q);

int peek(const Deque *q);

void clear(Deque *q);

int capacity(const Deque *q);

int size(const Deque *q);

int search(const Deque *q, int x);

void printQueue(const Deque *q);

void terminate(Deque *q);

#endif