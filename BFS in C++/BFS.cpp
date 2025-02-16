// #include <iostream>
// #include <list>

// using namespace std;

// class Graph {
//   int numVertices;
//   list<int>* adjLists;
//   bool* visited;

//    public:
//   Graph(int vertices);
//   void addEdge(int src, int dest);
//   void BFS(int startVertex);
// };

// Graph::Graph(int vertices) {
//   numVertices = vertices;
//   adjLists = new list<int>[vertices];
// }
// void Graph::addEdge(int src, int dest) {
//   adjLists[src].push_back(dest);
//   adjLists[dest].push_back(src);
// }

// void Graph::BFS(int startVertex) {
//   visited = new bool[numVertices];
//   for (int i = 0; i < numVertices; i++)
//     visited[i] = false;

//   list<int> queue;

//   visited[startVertex] = true;
//   queue.push_back(startVertex);

//   list<int>::iterator i;

//   while (!queue.empty()) {
//     int currVertex = queue.front();
//     cout << "Visited " << currVertex << " ";
//     queue.pop_front();

//     for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
//       int adjVertex = *i;
//       if (!visited[adjVertex]) {
//         visited[adjVertex] = true;
//         queue.push_back(adjVertex);
//       }
//     }
//   }
// }

// int main() {
//   Graph g(4);
//   g.addEdge(0, 1);
//   g.addEdge(0, 2);
//   g.addEdge(1, 2);
//   g.addEdge(2, 0);
//   g.addEdge(2, 3);
//   g.addEdge(3, 3);
//   g.BFS(2);
//   return 0;
// }
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int numVertices;
    vector<vector<int>> adjLists;

public:
    Graph(int vertices) : numVertices(vertices), adjLists(vertices) {}

    void addEdge(int src, int dest) {
        adjLists[src].push_back(dest);
        adjLists[dest].push_back(src);
    }

    void BFS(int startVertex) {
        vector<bool> visited(numVertices, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << "Visited " << curr << " ";

            for (int neighbor : adjLists[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.BFS(2);
    return 0;
}
