// Detect cycle in undirected graph --> DFS
// when we want to detect cycle in a undirected graph then should check what will be its parent and if one of its adjacent is
// already and not its parent then we conclude that there exists a cycle in the graph...
// in DfS the parent will se stored in recursion itself unlike BFS where we store it in array/vector and check it..

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

void add_edge(vector<int> vec[], int u, int v)
{
    vec[u].push_back(v);
    vec[v].push_back(u);
}

bool dfs(vector<int> vec[], vector<bool> &visited, int parent, int source)
{
    visited[source] = true;
    for (int i = 0; i < vec[source].size(); i++)
    {
        int adjacent = vec[source][i];
        if (visited[adjacent] == false)
        {
            if (dfs(vec, visited, source, adjacent) == true)
            {
                return true;
            }
        }
        else if (visited[adjacent] == true && parent != adjacent)
        {
            return true;
        }
    }
    return false;
}

bool dfs_rec(vector<int> vec[], int v)
{
    vector<bool> visited(v, false);
    int parent = -1;
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            if (dfs(vec, visited, parent, i) == true)
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

    if (dfs_rec(adj, v))
    {
        cout << "It contains an cycle!!" << endl;
    }
    else
    {
        cout << "It doesnt contain an cycle!!" << endl;
    }

    return 0;
}