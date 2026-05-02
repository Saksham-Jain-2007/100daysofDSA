#include <stdio.h>
#include <limits.h>

#define MAX 105

int graph[MAX][MAX];
int selected[MAX];
int n, m;

int prim() {
    int key[MAX];
    int total = 0;

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        selected[i] = 0;
    }

    key[1] = 0;

    for (int count = 1; count <= n; count++) {
        int u = -1;
        int min = INT_MAX;

        for (int i = 1; i <= n; i++) {
            if (!selected[i] && key[i] < min) {
                min = key[i];
                u = i;
            }
        }

        selected[u] = 1;
        total += key[u];

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !selected[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    return total;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    printf("%d\n", prim());

    return 0;
}
