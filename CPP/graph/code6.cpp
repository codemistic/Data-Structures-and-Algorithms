// Shortest Path in Unweighted Graph
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

void add_edge(vector<int> vec[], int u, int v)
{
    vec[u].push_back(v);
    vec[v].push_back(u);
}

void find_sd(vector<int> vec[], int v, int source)
{
    vector<bool> visited(v, false);
    vector<int> dist(v, INT_MAX);

    queue<int> q;
    q.push(source);
    dist[source] = 0;
    visited[source] = true;

    while (q.empty() == false)
    {
        int curr = q.front();
        q.pop();
        // cout<<"curr: "<<curr<<endl;
        for (int i = 0; i < vec[curr].size(); i++)
        {
            int adjacent = vec[curr][i];
            // cout<<"curr: "<<curr<<" adjacent: "<<adjacent<<endl;
            if (visited[adjacent] == false)
            {
                dist[adjacent] = dist[curr] + 1;
                visited[adjacent] = true;
                q.push(adjacent);
            }
        }
    }
    cout << "CHECK DISTANCE: " << endl;
    for (int i = 0; i < dist.size(); i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
    return;
}

int main()
{
    int v;
    v = 6;
    vector<int> adj[v];

    // adding edge to graph
    add_edge(adj, 0, 1);
    add_edge(adj, 0, 2);
    add_edge(adj, 0, 3);
    add_edge(adj, 1, 4);
    add_edge(adj, 1, 5);
    add_edge(adj, 2, 5);

    // finding shortes distance
    int source = 0;
    find_sd(adj, v, source);
    return 0;
}