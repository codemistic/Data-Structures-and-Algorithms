#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_set<int> &artpoints, vector<int> &time, vector<int> &lowest, vector<int> adj[],
         vector<int> &visited, int node, int &currTime, int parent)
{
    visited[node] = 1;
    time[node] = lowest[node] = currTime++;
    for (int adjacent : adj[node])
    {
        if (adjacent == parent)
            continue;

        if (visited[adjacent] == 0)
        {
            dfs(artpoints, time, lowest, adj, visited, adjacent, currTime, node);
            lowest[node] = min(lowest[node], lowest[adjacent]);

            if (parent != -1 and lowest[adjacent] >= time[node])
                artpoints.insert(node);
        }

        lowest[node] = min(lowest[node], lowest[adjacent]);
    }
    // specific case for starting point
    if (parent == -1 and adj[node].size() > 1)
    {
        for (int adjacent : adj[node])
        {
            if (lowest[adjacent] > time[node])
            {
                artpoints.insert(node);
                break;
            }
        }
    }
}

int main()
{
    int N = 11;
    vector<int> time(N, 0), lowest(N, INT_MAX), visited(N, 0);
    unordered_set<int> artpoints;

    int edges;
    cin >> edges;
    vector<int> adj[N];
    while (edges--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int currTime = 1;
    for (int i = 0; i < N; i++)
    {
        if (visited[i])
            continue;
        dfs(artpoints, time, lowest, adj, visited, i, currTime, -1);
    }

    for (int i : artpoints)
        cout << i << endl;
}