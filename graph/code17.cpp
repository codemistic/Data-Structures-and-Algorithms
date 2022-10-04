// In this code we will do shortest path code by bellman ford algorithm
// This code is dp implementation where we store result for (x-1)th edge and use it for xth edge
// we run one loop for v-1 cause in worst case we can go to last node in v-1 time
// and inside that loop we do relaxation of all edges

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

void add_edge(vector<pair<int, int>> vec[], int u, int v, int weight)
{
    vec[u].push_back({v, weight});
}

struct node
{
    int u, v, weight;
};

void bellman_ford(vector<pair<int, int>> vec[], int v, int source)
{
    vector<node> edges;
    vector<int> dist(v, inf);
    dist[source] = 0;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            edges.push_back({i, vec[i][j].first, vec[i][j].second});
        }
    }

    for (int i = 0; i < v - 1; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            node curr = edges[j];

            int curr_u = curr.u, curr_v = curr.v, curr_weight = curr.weight;
            if (dist[curr_v] > dist[curr_u] + curr_weight)
            {
                dist[curr_v] = dist[curr_u] + curr_weight;
            }
        }
    }

    cout << "FINAL SHORTEST DISTANCES VIA BELLMAN FORD ALGORITHM: " << endl;
    for (int i = 0; i < dist.size(); i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main()
{
    int v = 4;
    vector<pair<int, int>> adj[v];

    // adding edges now
    add_edge(adj, 0, 1, 1);
    add_edge(adj, 0, 2, 4);
    add_edge(adj, 1, 2, -3);
    add_edge(adj, 1, 3, 2);
    add_edge(adj, 2, 3, 3);

    int source = 0;
    bellman_ford(adj, v, source);

    return 0;
}