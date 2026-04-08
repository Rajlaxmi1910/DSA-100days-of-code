#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];   // adjacency matrix
int visited[MAX];
int stack[MAX];
int top = -1;
int V;

// DFS function
void dfs(int node) {
    visited[node] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i);
        }
    }

    // Push to stack after visiting all neighbors
    stack[++top] = node;
}

// Topological sort function
void topologicalSort() {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Print stack in reverse order
    printf("Topological Order: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

// Main function
int main() {
    int edges;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize graph
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;  // directed edge
    }

    topologicalSort();

    return 0;
}