#include <stdio.h>
#include <stdlib.h>
#include "Red Black Tree.h"

static Tree* createTree() {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    Node* nil = (Node*)malloc(sizeof(Node));
    nil->color = BLACK;
    nil->left = nil->right = nil->parent = nil;
    tree->nil = nil;
    tree->root = nil;

    return tree;
}

void LL(Tree* t, Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != t->nil) y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == t->nil)        t->root = y;
    else if (x == x->parent->left)  x->parent->left  = y;
    else                            x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void RR(Tree* t, Node* x) {
    Node* y = x->left;
    x->left = y->right;
    if (y->right != t->nil) y->right->parent = x;
    y->parent = x->parent;
    if (x->parent == t->nil)        t->root = y;
    else if (x == x->parent->right) x->parent->right = y;
    else                            x->parent->left  = y;
    y->right = x;
    x->parent = y;
}

void transplant(Tree* t, Node* u, Node* v) {
    if (u->parent == t->nil)       t->root = v;
    else if (u == u->parent->left) u->parent->left  = v;
    else                           u->parent->right = v;
    v->parent = u->parent;
}

Node* minimum(Tree* t, Node* x) {
    while (x->left != t->nil) x = x->left;
    return x;
}

void insert(Tree* t, int key) {
    Node* z = (Node*)calloc(1, sizeof(Node));
    z->key = key;
    z->color = RED;
    z->left = z->right = z->parent = t->nil;
    Node* p = t->nil;
    Node* c = t->root;
    while (c != t->nil) {
        p = c;
        c = (key < c->key) ? c->left : c->right;
    }
    z->parent = p;
    if (p == t->nil)        t->root = z;
    else if (key < p->key)  p->left  = z;
    else                    p->right = z;
    while (z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            Node* u = z->parent->parent->right;
            if (u->color == RED) {
                z->parent->color = BLACK;
                u->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else {
                if (z == z->parent->right) {
                    z = z->parent;
                    LL(t, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                RR(t, z->parent->parent);
            }
        }
        else {
            Node* u = z->parent->parent->left;
            if (u->color == RED) {
                z->parent->color = BLACK;
                u->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else {
                if (z == z->parent->left) {
                    z = z->parent;
                    RR(t, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                LL(t, z->parent->parent);
            }
        }
    }
    t->root->color = BLACK;
}

void erase(Tree* t, Node* z) {
    Node* y = z;
    Node* x;
    Color y_color = y->color;
    if (z->left == t->nil) {
        x = z->right;
        transplant(t, z, z->right);
    }
    else if (z->right == t->nil) {
        x = z->left;
        transplant(t, z, z->left);
    }
    else {
        y = minimum(t, z->right);
        y_color = y->color;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        }
        else {
            transplant(t, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(t, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    free(z);
    if (y_color == BLACK) {
        while (x != t->root && x->color == BLACK) {
            if (x == x->parent->left) {
                Node* w = x->parent->right;
                if (w->color == RED) {
                    w->color = BLACK; x->parent->color = RED;
                    LL(t, x->parent);
                    w = x->parent->right;
                }
                if (w->left->color == BLACK && w->right->color == BLACK) {
                    w->color = RED; x = x->parent;
                }
                else {
                    if (w->right->color == BLACK) {
                        w->left->color = BLACK; w->color = RED;
                        RR(t, w);
                        w = x->parent->right;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->right->color = BLACK;
                    LL(t, x->parent);
                    x = t->root;
                }
            }
            else {
                Node* w = x->parent->left;
                if (w->color == RED) {
                    w->color = BLACK; x->parent->color = RED;
                    RR(t, x->parent);
                    w = x->parent->left;
                }
                if (w->right->color == BLACK && w->left->color == BLACK) {
                    w->color = RED; x = x->parent;
                }
                else {
                    if (w->left->color == BLACK) {
                        w->right->color = BLACK; w->color = RED;
                        LL(t, w);
                        w = x->parent->left;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->left->color = BLACK;
                    RR(t, x->parent);
                    x = t->root;
                }
            }
        }
        x->color = BLACK;
    }
}

Node* search(Tree* t, int key) {
    Node *x = t->root;
    while (x != t->nil && key != x->key)
        x = (key < x->key) ? x->left : x->right;
    return x;
}

void LVR(const Tree* t, const Node* root) {
    if (root == t->nil) return;

    LVR(t, root->left);
    printf("(%d,%c) ", root->key, root->color == RED ? 'R' : 'B');
    LVR(t, root->right);
}

int main() {
    Tree *t = createTree();

    int keys[] = { 20, 15, 25, 10, 18, 22, 30, 5, 12, 17, 19 };
    size_t nkeys = sizeof(keys) / sizeof(keys[0]);

    for (size_t i = 0; i < nkeys; ++i)
        insert(t, keys[i]);

    puts("== In-order after insert ==");
    LVR(t, t->root);
    puts("\n");

    int dels[] = { 15, 22, 20 };
    size_t ndel = sizeof(dels) / sizeof(dels[0]);

    for (size_t i = 0; i < ndel; ++i) {
        Node *z = search(t, dels[i]);
        if (z != t->nil) erase(t, z);
    }

    puts("== In-order after erase ==");
    LVR(t, t->root);
    puts("\n");

    return 0;
}