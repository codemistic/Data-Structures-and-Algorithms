def floyd_warshall(graph):
    """
    Floyd-Warshall algorithm for finding shortest paths in a graph.
    """
    dist = graph
    n = len(graph)
    for k in range(n):
        for i in range(n):
            for j in range(n):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
    return dist
