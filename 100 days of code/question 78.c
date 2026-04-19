#include <stdio.h>
#include <limits.h>

#define MAX 100

int n, graph[MAX][MAX];

int minKey(int key[], int visited[]) {
    int min = INT_MAX, min_index;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0 && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

int primMST() {
    int parent[MAX];   // Store MST
    int key[MAX];      // Minimum weights
    int visited[MAX];  // Visited nodes

    // Initialize
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[0] = 0;      // Start from node 0
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, visited);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && visited[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Calculate total weight
    int total = 0;
    for (int i = 1; i < n; i++) {
        total += graph[i][parent[i]];
    }

    return total;
}

int main() {
    int m, u, v, w;

    scanf("%d %d", &n, &m);

    // Initialize graph
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        u--; v--; // convert to 0-based index
        graph[u][v] = w;
        graph[v][u] = w;
    }

    printf("%d\n", primMST());

    return 0;
}