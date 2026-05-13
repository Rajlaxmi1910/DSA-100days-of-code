#include <stdio.h>
#define MAX 10
int adj[MAX][MAX], visited[MAX], n;
void addEdge(int src, int dest)
{
    adj[src][dest] = 1;
    adj[dest][src] = 1;
}
void DFS(int start)
{
    int stack[MAX];
    int top = -1;
    int i, node;
    stack[++top] = start;
    while(top != -1)
    {
        node = stack[top--];
        if(visited[node] == 0)
        {
            printf("%d ", node);
            visited[node] = 1;
            for(i = n-1; i >= 0; i--)
            {
                if(adj[node][i] == 1 && visited[i] == 0)
                {
                    stack[++top] = i;
                }
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
    printf("DFS Traversal: ");
    DFS(start);
    return 0;
}
