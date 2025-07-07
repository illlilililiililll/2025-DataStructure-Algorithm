#ifndef DEQUE_H
#define DEQUE_H

typedef struct Deque {
    int max;
    int ptr;
    int front;
    int rear;
    int *data;
} Deque;

void init(Deque *Deque, int max);

bool empty(const Deque *q);

void append_front(Deque *q, int x);

void append_rear(Deque *q, int x);

int delete_front(Deque *q);

int delete_rear(Deque *q);

void clear(Deque *q);

int capacity(const Deque *q);

int size(const Deque *q);

int search(const Deque *q, int x);

void printDeque(const Deque *q);

void terminate(Deque *q);

#endif