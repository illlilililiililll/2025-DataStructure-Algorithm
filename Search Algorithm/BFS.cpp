#include <stdio.h>
#include <stdlib.h>
#include "../Linear DataStructures/Queue/Queue.h"
#include "../Nonlinear DataStructures/Graph/Graph.h"

void BFS(Graph* g, int v) {
    int n = g->max;

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    circularQueue q;
    init(&q, n);

    visited[v] = 1;

    printf("%d", v);
    enqueue(&q, v);
    while(!empty(&q)) {
        v = dequeue(&q);
        for (int w = 0; w < g->n; w++)
            if (g->Matrix[v][w] && !visited[w]) {
                visited[w] = 1;
                printf(" -> %d", w);
                enqueue(&q, w);
            }
    }
    printf("\n");

    terminate(&q);
}

int main(void){
    Graph *g;
    g=(Graph *)malloc(sizeof(Graph));
    init(g, 7, UNDIRECTED, UNWEIGHTED);
    for(int i=0;i<7;i++)
        insertVertex(g,i);

    insertEdge(g,0,1);
    insertEdge(g,0,2);
    insertEdge(g,1,3);
    insertEdge(g,1,4);
    insertEdge(g,2,5);
    insertEdge(g,2,6);

    BFS(g,0);
    terminate(g);

    return 0;
}