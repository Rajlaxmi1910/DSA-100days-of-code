#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];   // Adjacency matrix
int visited[MAX];
int n;

// DFS function
void dfs(int node) {
    visited[node] = 1;
    
    for(int i = 1; i <= n; i++) {
        if(adj[node][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int m, u, v;
    int components = 0;

    scanf("%d %d", &n, &m);

    // Initialize
    for(int i = 1; i <= n; i++) {
        visited[i] = 0;
        for(int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    // Input edges
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // Undirected graph
    }

    // Count components
    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            dfs(i);
            components++;
        }
    }

    printf("%d\n", components);

    return 0;
}