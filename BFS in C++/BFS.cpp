#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int numVertices;
    vector<vector<int>> adjLists;

public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void BFS(int startVertex);
};

Graph::Graph(int vertices) : numVertices(vertices), adjLists(vertices) {}

void Graph::addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
}

void Graph::BFS(int startVertex) {
    vector<bool> visited(numVertices, false);
    queue<int> q;

    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        int currVertex = q.front();
        cout << "Visited " << currVertex << " ";
        q.pop();

        for (int adjVertex : adjLists[currVertex]) {
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                q.push(adjVertex);
            }
        }
    }
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.BFS(2);
    return 0;
}
