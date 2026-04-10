#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// Min Heap structure
typedef struct {
    int vertex;
    int dist;
} HeapNode;

HeapNode heap[MAX];
int heapSize = 0;

// Swap heap nodes
void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(int index) {
    while(index && heap[(index - 1) / 2].dist > heap[index].dist) {
        swap(&heap[(index - 1) / 2], &heap[index]);
        index = (index - 1) / 2;
    }
}

// Heapify down
void heapifyDown(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < heapSize && heap[left].dist < heap[smallest].dist)
        smallest = left;

    if(right < heapSize && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if(smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert into heap
void push(int vertex, int dist) {
    heap[heapSize].vertex = vertex;
    heap[heapSize].dist = dist;
    heapifyUp(heapSize);
    heapSize++;
}

// Extract minimum
HeapNode pop() {
    HeapNode root = heap[0];
    heap[0] = heap[--heapSize];
    heapifyDown(0);
    return root;
}

// Add edge
void addEdge(Node* adj[], int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Dijkstra Algorithm
void dijkstra(Node* adj[], int V, int src) {
    int dist[MAX];

    for(int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(src, 0);

    while(heapSize > 0) {
        HeapNode node = pop();
        int u = node.vertex;

        Node* temp = adj[u];
        while(temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if(dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                push(v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print result
    for(int i = 0; i < V; i++)
        printf("Distance from %d to %d = %d\n", src, i, dist[i]);
}

// Driver Code
int main() {
    int V = 5;
    Node* adj[MAX] = {NULL};

    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 2, 4);
    addEdge(adj, 1, 2, 1);
    addEdge(adj, 1, 3, 7);
    addEdge(adj, 2, 4, 3);
    addEdge(adj, 3, 4, 1);

    dijkstra(adj, V, 0);

    return 0;
}