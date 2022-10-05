// Detect cycle in undirected graph with BFS
// so in undirected graphs mainly we find who is the parent and if found some adjacent whose adjacent
// is visited and also is not is not its parent the we can surely say that we have a cycle.
// In case of BFS we make parent array and thats how we check parent..
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

void add_edge(vector<int> vec[], int u, int v)
{
    vec[u].push_back(v);
    vec[v].push_back(u);
}

bool bfs_find(vector<int> vec[], vector<bool> &visited, vector<int> &parent, int source)
{
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while (q.empty() == false)
    {
        int curr = q.front();
        q.pop();
        for (int i = 0; i < vec[curr].size(); i++)
        {
            int adjacent = vec[curr][i];
            if (visited[adjacent] == false)
            {
                visited[adjacent] = true;
                q.push(adjacent);
                parent[adjacent] = curr;
            }
            else if (visited[adjacent] == true && parent[curr] != adjacent)
            {
                return true;
            }
        }
    }
    return false;
}

bool bfs_rec(vector<int> vec[], int v)
{
    vector<bool> visited(v, false);
    vector<int> parent(v, -1);
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            if (bfs_find(vec, visited, parent, i) == true)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int v;
    v = 6;
    vector<int> adj[v];

    // adding edges now
    add_edge(adj, 0, 1);
    add_edge(adj, 0, 2);
    add_edge(adj, 0, 3);
    add_edge(adj, 1, 4);
    add_edge(adj, 1, 5);
    add_edge(adj, 2, 5);

    // find if it has a loop or not
    if (bfs_rec(adj, v))
    {
        cout << "It has a loop !!" << endl;
    }
    else
    {
        cout << "It doesnt have a loop!!" << endl;
    }
    return 0;
}