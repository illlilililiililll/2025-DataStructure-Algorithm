#include <stdio.h>
#include <stdlib.h>
#include "../Linear DataStructures/Stack/Stack.h"
#include "../Nonlinear DataStructures/Graph/Graph.h"

#define INF 2147483647

void DFS(Graph* g, int v) {
    int visited[g->max];
    for (int i = 0; i < g->max; ++i) visited[i] = 0;

    Stack s;
    init(&s, g->max);

    visited[v] = 1;   // 시작 노드 방문 체크 먼저
    push(&s, v);

    while (!empty(&s)) {
        int current = pop(&s);
        printf("%d ", current);

        for (int w = 0; w < g->n; w++) {
            if (g->Matrix[current][w] && !visited[w]) {
                push(&s, w);
                visited[w] = 1;
            }
        }
    }
    printf("\n");

    terminate(&s);
}


int main(){
    Graph *g;
    g = (Graph *)malloc(sizeof(Graph));
    init(g, 5, UNDIRECTED, UNWEIGHTED);
    for(int i = 0;i < 7;i++)
        insertVertex(g,i);
    
    insertEdge(g,0,1);
    insertEdge(g,0,2);
    insertEdge(g,1,3);
    insertEdge(g,1,4);
    insertEdge(g,2,5);
    insertEdge(g,2,6);

    DFS(g,0);
    terminate(g);

    return 0;
}