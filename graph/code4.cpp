// Breadth first search
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

void add_edge(vector<int> vec[], int u, int v)
{
    vec[u].push_back(v);
    vec[v].push_back(u);
}

void bfs(vector<int> vec[], int v, int source, vector<bool> &visited)
{
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (q.empty() == false)
    {
        int curr = q.front();
        q.pop();

        cout << curr << " ";
        for (int i = 0; i < vec[curr].size(); i++)
        {
            int adjacent = vec[curr][i];
            if (visited[adjacent] == false)
            {
                q.push(adjacent);
                visited[adjacent] = true;
            }
        }
    }
}

void bfs_recursive(vector<int> vec[], int v)
{
    vector<bool> visited(v, false);
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            bfs(vec, v, i, visited);
        }
    }
}

int main()
{
    int v;
    v = 6;
    vector<int> adj[v];

    // Adding edges from this point
    add_edge(adj, 0, 1);
    add_edge(adj, 0, 2);
    add_edge(adj, 0, 3);
    add_edge(adj, 1, 5);
    add_edge(adj, 2, 5);
    add_edge(adj, 1, 4);

    cout << "Breadth First Search is: " << endl;

    bfs_recursive(adj, v);

    return 0;
}