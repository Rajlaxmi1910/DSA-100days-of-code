#include <stdio.h>
#define MAX 10
int adj[MAX][MAX], visited[MAX], n;
void addEdge(int src, int dest)
{
    adj[src][dest] = 1;
    adj[dest][src] = 1;
}
void BFS(int start)
{
    int queue[MAX];
    int front = -1, rear = -1;
    int i, node;
    queue[++rear] = start;
    visited[start] = 1;
    while(front != rear)
    {
        node = queue[++front];
        printf("%d ", node);
        for(i = 0; i < n; i++)
        {
            if(adj[node][i] == 1 && visited[i] == 0)
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}
void display()
{
    int i, j;
    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int i, j, edges, src, dest, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            adj[i][j] = 0;
    }
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    printf("Enter edges:\n");
    for(i = 0; i < edges; i++)
    {
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }
    display();
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    for(i = 0; i < n; i++)
        visited[i] = 0;
    printf("BFS Traversal: ");
    BFS(start);
    return 0;
}
