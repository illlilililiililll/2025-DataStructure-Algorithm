#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

#define INF 2147483647

void init(Graph* g, int n, Directed dir, Weighted w) {
    g->dir = dir;
    g->w = w;
    g->n = 0;
    g->max = n;

    g->Matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        g->Matrix[i] = (int *) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
            (i != j) ? g->Matrix[i][j] = INF : g->Matrix[i][j] = 0;
    }
}

void insertVertex(Graph* g, int vertex) {
    int n = g->max;
    if (++g->n > n) {
        int** arr = (int**)malloc((n + 1) * sizeof(int *));
        for (int i = 0; i < n + 1; i++) {
            arr[i] = (int *)malloc((n + 1) * sizeof(int));
            for (int j = 0; j < n + 1; j++) {
                if (i < n && j < n)
                    arr[i][j] = g->Matrix[i][j];
                else
                    arr[i][j] = INF;
            }
            arr[i][i] = 0;

            if (i < n) free(g->Matrix[i]);
        }
        free(g->Matrix);

        g->Matrix = arr;
        g->max++;
    }
}

void insertEdge(Graph* g, int start, int end, int weight=1) {
    if (start >= g->n || end >= g->n)
        return;

    int w = weight;
    if (g->w == UNWEIGHTED)
        w = 1;

    g->Matrix[start][end] = w;
    if (g->dir == UNDIRECTED)
        g->Matrix[end][start] = w;
}

void adjacencyMatrix(const Graph* g) {
    for(int i = 0;i < g->n; i++) {
        for(int j = 0; j < g->n; j++)
            if (g->Matrix[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", g->Matrix[i][j]);

        printf("\n");
    }
}

void terminate(Graph* g) {
    for (int i = 0; i < g->max; i++)
        free(g->Matrix[i]);
    free(g->Matrix);
}

int main() {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    init(g, 2, DIRECTED, WEIGHTED);

    for (int i = 0; i < 4; i++)
        insertVertex(g, i);

    insertEdge(g, 0, 1, 3);
    insertEdge(g, 0, 2, 2);
    insertEdge(g,0,3, 7);
    insertEdge(g,1,2, -1);
    insertEdge(g,2,3, INF);

    adjacencyMatrix(g);

    return 0;
}