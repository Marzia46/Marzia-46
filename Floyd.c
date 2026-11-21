#include <stdio.h>

#define INF 99999

int main() {
    int n, a[10][10];
    int i, j, k;

    // Input number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Input cost matrix
    printf("Enter cost matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);

            // Replace 0 with INF if nodes are different
            if(i != j && a[i][j] == 0)
                a[i][j] = INF;
        }
    }

    // Floyd-Warshall Algorithm
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {

                if(a[i][k] != INF && a[k][j] != INF &&
                   a[i][k] + a[k][j] < a[i][j]) {

                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }

    // Print shortest distance matrix
    printf("Shortest distance matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {

            if(a[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}