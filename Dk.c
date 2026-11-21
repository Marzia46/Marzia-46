#include <stdio.h>

#define INF 99999

int main() {
    int n, cost[10][10], d[10], visited[10];
    int i, j, u, min, start;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            if(i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("Enter starting node (0 to %d): ", n-1);
    scanf("%d", &start);

    for(i = 0; i < n; i++) {
        d[i] = cost[start][i];
        visited[i] = 0;
    }

    d[start] = 0;
    visited[start] = 1;

    for(i = 1; i < n; i++) {
        min = INF;
        u = -1;

        for(j = 0; j < n; j++) {
            if(!visited[j] && d[j] < min) {
                min = d[j];
                u = j;
            }
        }

        if(u == -1)
            break;

        visited[u] = 1;

        for(j = 0; j < n; j++) {
            if(!visited[j] && cost[u][j] != INF &&
               d[u] + cost[u][j] < d[j]) {
                d[j] = d[u] + cost[u][j];
            }
        }
    }

    printf("Shortest distances:\n");

    for(i = 0; i < n; i++) {
        if(d[i] == INF)
            printf("%d -> Not reachable\n", i);
        else
            printf("%d -> %d\n", i, d[i]);
    }

    return 0;
}