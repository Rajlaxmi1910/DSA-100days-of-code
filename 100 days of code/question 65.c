#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool dfs(int node, int parent, int** adj, int* adjSize, bool* visited) {
    visited[node] = true;
    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, adjSize, visited)) {
                return true;
            }
        }
        else if (neighbor != parent) {
            return true; // Cycle detected
        }
    }
    return false;
}
char* hasCycle(int** adj, int adjSize, int* adjColSize) {
    bool* visited = (bool*)calloc(adjSize, sizeof(bool));
    for (int i = 0; i < adjSize; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, adjColSize, visited)) {
                return "YES";
            }
        }
    }
    return "NO";
}