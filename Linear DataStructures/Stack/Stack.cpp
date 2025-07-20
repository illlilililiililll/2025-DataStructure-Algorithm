#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void init(Stack *s, int max) {
    s->init_max = s->max = max;
    s->ptr = 0;
    s->data = (int*)calloc(max, sizeof(int));
}

void push(Stack *s, int x) {
    if (s->ptr >= s->max)
        s->data = (int*)realloc(s->data, (++s->max) * sizeof(int));

    s->data[s->ptr++] = x;
}

int pop(Stack *s) {
    return s->data[--s->ptr];
}

int peek(const Stack *s) {
    return s->data[s->ptr-1];
}

void clear(Stack *s) {
    s->ptr = 0;
    s->max = s->init_max;
}

int capacity(const Stack *s) { // max length
    return s->max;
}

int size(const Stack *s) { // current length
    return s->ptr;
}

int search(const Stack *s, int x) {
    for (int i = 0; i < s->ptr; i++)
        if (s->data[i] == x)
            return i;

    return -1;
}

void printStack(const Stack *s) {
    printf("{ ");
    for (int i = 0; i < s->ptr; i++) {
        printf("%d", s->data[i]);
        if (i < s->ptr - 1) {
            printf(", ");
        }
    }
    printf(" }\n");
}

void terminate(Stack *s) {
    free(s->data);
    s->init_max = s->max = s->ptr = 0;
}