#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 1000
struct Node {
    int vertex;
    struct Node* next;
};
struct Graph {
    int V;
    struct Node* adj[MAX];
};
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
}
bool dfs(struct Graph* graph, int v, bool visited[], bool recStack[]) {
    visited[v] = true;
    recStack[v] = true;

    struct Node* temp = graph->adj[v];
    while (temp != NULL) {
        int neighbor = temp->vertex;

        if (!visited[neighbor]) {
            if (dfs(graph, neighbor, visited, recStack))
                return true;
        }
        else if (recStack[neighbor]) {
            return true; // cycle found
        }

        temp = temp->next;
    }

    recStack[v] = false; // remove from recursion stack
    return false;
}
bool isCycle(struct Graph* graph) {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            if (dfs(graph, i, visited, recStack))
                return true;
        }
    }
    return false;
}
int main() {
    int V = 4;
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1); // creates cycle

    if (isCycle(graph))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}