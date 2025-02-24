#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {
    int numVertices;
    list<int>* adjLists;

public:
    Graph(int vertices);
    ~Graph(); // Destructor to free memory
    void addEdge(int src, int dest);
    void BFS(int startVertex);
};

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists = new list<int>[vertices];
}

Graph::~Graph() {
    delete[] adjLists; // Free allocated memory
}

void Graph::addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
}

void Graph::BFS(int startVertex) {
    vector<bool> visited(numVertices, false); // Avoids memory leaks

    list<int> queue;
    visited[startVertex] = true;
    queue.push_back(startVertex);

    while (!queue.empty()) {
        int currVertex = queue.front();
        cout << "Visited " << currVertex << " ";
        queue.pop_front();

        for (int adjVertex : adjLists[currVertex]) {
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }
        }
    }
    cout << endl;
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.BFS(2);
    return 0;
}
