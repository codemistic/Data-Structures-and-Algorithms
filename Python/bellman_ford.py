# implementation of bellman-ford algorithm
def bellman_ford_algorithm(graph, source):
    """
    Bellman-Ford algorithm for finding the shortest path from a source node to all other nodes in a graph.
    :param graph: the graph
    :param source: the source node
    :return: a dictionary containing the shortest path from the source node to all other nodes
    """
    # initialize distance of source to 0
    distance = {node: float('inf') for node in graph}
    distance[source] = 0
    # relax edges repeatedly
    for _ in range(len(graph) - 1):
        for node in graph:
            for neighbour in graph[node]:
                if distance[node] + graph[node][neighbour] < distance[neighbour]:
                    distance[neighbour] = distance[node] + graph[node][neighbour]
    # check for negative-weight cycles
    for node in graph:
        for neighbour in graph[node]:
            if distance[node] + graph[node][neighbour] < distance[neighbour]:
                print('Graph contains a negative-weight cycle')
                return
    return distance

# example
if __name__ == '__main__':
    graph = {
        'A': {'B': 6, 'C': 5, 'D': 5},
        'B': {'C': 4},
        'C': {'B': -2, 'D': 7},
        'D': {'C': 6}
    }

    # note how shortest path from a to b is 3 (a -> c -> b)
    print(bellman_ford_algorithm(graph, 'A'))
