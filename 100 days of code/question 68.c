#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void topologicalSort(int n) {
    int i, j;
    int count = 0;
    int topo[MAX];

    // Initialize indegree
    for(i = 0; i < n; i++) {
        indegree[i] = 0;
    }

    // Calculate indegree
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(graph[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Add nodes with indegree 0 to queue
    for(i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            enqueue(i);
        }
    }

    // Process queue
    while(!isEmpty()) {
        int node = dequeue();
        topo[count++] = node;

        for(i = 0; i < n; i++) {
            if(graph[node][i] == 1) {
                indegree[i]--;
                if(indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }

    // Check for cycle
    if(count != n) {
        printf("Cycle exists! Topological sort not possible.\n");
        return;
    }

    // Print result
    printf("Topological Order: ");
    for(i = 0; i < count; i++) {
        printf("%d ", topo[i]);
    }
    printf("\n");
}

int main() {
    int n, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    topologicalSort(n);

    return 0;
}