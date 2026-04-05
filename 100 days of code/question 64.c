#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
    int *data;
    int front, rear, size;
} Queue;
Queue* createQueue(int n) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)malloc(n * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}
void enqueue(Queue* q, int val) {
    q->rear++;
    q->data[q->rear] = val;
    q->size++;
}
int dequeue(Queue* q) {
    int val = q->data[q->front];
    q->front++;
    q->size--;
    return val;
}
bool isEmpty(Queue* q) {
    return q->size == 0;
}

int* bfs(int** adj, int n, int* colSize, int s, int* returnSize) {
    bool* visited = (bool*)calloc(n, sizeof(bool));
    int* result = (int*)malloc(n * sizeof(int));
    Queue* q = createQueue(n);
    int idx = 0;
    enqueue(q, s);
    visited[s] = true;
    while (!isEmpty(q)) {
        int node = dequeue(q);
        result[idx++] = node;
        for (int i = 0; i < colSize[node]; i++) {
            int neighbor = adj[node][i];
            if (!visited[neighbor]) {
                enqueue(q, neighbor);
                visited[neighbor] = true;
            }
        }
    }
    *returnSize = idx;
    return result;
}