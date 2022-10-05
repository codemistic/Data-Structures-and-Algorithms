// Depth First search
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

void add_edge(vector<int> vec[], int u, int v)
{
    vec[u].push_back(v);
    vec[v].push_back(u);
}

void dfs(vector<int> vec[], int source, vector<bool> &visited)
{
    visited[source] = true;
    cout << source << " ";
    for (int i = 0; i < vec[source].size(); i++)
    {
        int adjacent = vec[source][i];
        if (visited[adjacent] == false)
        {
            dfs(vec, adjacent, visited);
        }
    }
}

void dfs_rec(vector<int> vec[], int v)
{
    vector<bool> visited(v, false);
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            dfs(vec, i, visited);
        }
    }
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

    cout << "DEPTH FIRST SEARCH: " << endl;

    dfs_rec(adj, v);
    return 0;
}