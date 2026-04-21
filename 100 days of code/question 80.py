def floyd_warshall(n, graph):
    # Replace -1 with infinity (except diagonal)
    INF = float('inf')
    
    dist = [[INF]*n for _ in range(n)]
    
    for i in range(n):
        for j in range(n):
            if graph[i][j] == -1:
                continue
            dist[i][j] = graph[i][j]
        
        dist[i][i] = 0  # Distance to itself is always 0

    # Floyd-Warshall Algorithm
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][k] != INF and dist[k][j] != INF:
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

    # Convert INF back to -1
    for i in range(n):
        for j in range(n):
            if dist[i][j] == INF:
                dist[i][j] = -1

    return dist


# -------- INPUT --------
n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]

# -------- PROCESS --------
result = floyd_warshall(n, graph)

# -------- OUTPUT --------
for row in result:
    print(*row)