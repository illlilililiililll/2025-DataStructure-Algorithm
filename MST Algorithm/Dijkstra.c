#include <stdio.h>
#define INF 2147483647

void Dijkstra(int n, int Graph[n][n], int start) {
    int cost[n][n], distance[n], pred[n];
    int visited[n], count, min, next;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (Graph[i][j] == 0)
                cost[i][j] = INF;
            else
                cost[i][j] = Graph[i][j];

    for (int i = 0; i < n; i++) {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    while (count < n - 1) {
        min = INF;

        for (int i = 0; i < n; i++)
            if (distance[i] < min && !visited[i]) {
                min = distance[i];
                next = i;
            }

        visited[next] = 1;
        for (int i = 0; i < n; i++)
            if (!visited[i])
                if (min + cost[next][i] < distance[i]) {
                    distance[i] = min + cost[next][i];
                    pred[i] = next;
                }
        count++;
    }

    // Printing the distance
    for (int i = 0; i < n; i++)
        if (i != start) {
            printf("\n%d -> %d: %d", start, i, distance[i]);
        }
}
int main() {
    int n = 7;
    int Graph[7][7] = {
            {0, 0, 1, 2, 0, 0, 0},
            {0, 0, 2, 0, 0, 3, 0},
            {1, 2, 0, 1, 3, 0, 0},
            {2, 0, 1, 0, 0, 0, 1},
            {0, 0, 3, 0, 0, 2, 0},
            {0, 3, 0, 0, 2, 0, 1},
            {0, 0, 0, 1, 0, 1, 0}
    };

    Dijkstra(n, Graph, 0);

    return 0;
}