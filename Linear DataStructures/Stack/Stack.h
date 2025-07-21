#ifndef STACK_H
#define STACK_H

typedef struct Stack {
    int init_max;
    int max;
    int ptr;
    int *data;
} stack;

void init(Stack *Deque, int max);
bool empty(const Stack *s);
void push(Stack *s, int x);
int pop(Stack *s);
int peek(const Stack *s);
void clear(Stack *s);
int capacity(const Stack *s);
int size(const Stack *s);
int search(const Stack *s, int x);
void printStack(const Stack *s);
void terminate(Stack *s);

#endif