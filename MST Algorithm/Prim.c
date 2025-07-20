#include <stdio.h>

#define INF 2147483647

int minVertex(int n, int distance[], int selected[]) {
    int v = -1;

    for (int i = 0; i < n; i++) {
        if (selected[i] == 0) {
            v = i;
            break;
        }
    }

    for (int i = 0; i < n; i++)
        if (selected[i] == 0 && distance[i] < distance[v])
            v = i;

    return v;
}

void prim(int n, int weight[n][n], int start) {
    int distance[n];
    int selected[n];
    int MST[n];

    for (int i = 0; i < n; i++) {
        distance[i] = INF;
        selected[i] = 0;
    }

    distance[start] = 0;

    for (int i = 0; i < n; i++) {
        int u = minVertex(n, distance, selected);
        selected[u] = 1;

        if (distance[u] == INF)
            return;

        (i != n - 1)? printf("%d -> ", u) : printf("%d", u);

        for (int v = 0; v < n; v++)
            if (weight[u][v] != INF && selected[v] == 0 && weight[u][v] < distance[v])
                distance[v] = weight[u][v];
    }
}

int main() {
    int n = 7;
    int Graph[7][7] = {
            {0, 29, INF, INF, INF, 10, INF},
            {29, 0, 16, INF, INF, INF, 15},
            {INF, 16, 0, 12, INF, INF, INF},
            {INF, INF, 12, 0, 22, INF, 18},
            {INF, INF, INF, 22, 0, 27, 25},
            {10, INF, INF, INF, 27, 0, INF},
            {INF, 15, INF, 18, 25, INF, 0}
    };

    prim(n, Graph, 0);

    return 0;
}