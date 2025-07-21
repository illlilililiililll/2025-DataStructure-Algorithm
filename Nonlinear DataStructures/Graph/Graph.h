#ifndef GRAPH_H
#define GRAPH_H

typedef enum { UNDIRECTED = 0, DIRECTED = 1 } Directed;
typedef enum { UNWEIGHTED = 0, WEIGHTED = 1 } Weighted;

typedef struct Graph{
    Directed dir;
    Weighted w;
    int n;
    int max;
    int** Matrix;
} Graph;

void init(Graph* g, int n, Directed dir, Weighted w);

void insertVertex(Graph* g, int vertex);

void insertEdge(Graph* g, int start, int end, int weight=1);

void adjacencyMatrix(const Graph* g);

void terminate(Graph* g);

#endif