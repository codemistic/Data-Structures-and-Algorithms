// In this code we will implement Dijstra's algorithm
// Dijstra's works same way as Prim's algorithm with only difference
// (in prims we consider only edges) (in dijstra we consider dist upto some node with its adjacent)

// here we take one node check all adjacents of it and chec if we can get any shorter distance from our current point
// if we get shorter we consider it.. otherwise ignore it

// here we will use priority queue to get that node which is at minimum distance currently so we can get minimum distance for its adjacent

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

void add_edge(vector<pair<int, int>> vec[], int u, int v, int weight)
{
    vec[u].push_back({v, weight});
    vec[v].push_back({u, weight});
}

// without priority queue
void dijstra1(vector<pair<int, int>> vec[], int v, int source)
{
    vector<bool> mst(v, false);
    vector<int> dist(v, INT_MAX);
    dist[source] = 0;

    for (int i = 0; i < v; i++)
    {
        int u = -1;
        for (int j = 0; j < dist.size(); j++)
        {
            if (mst[j] == false && (u == -1 || dist[j] < dist[u]))
            {
                u = j;
            }
        }
        mst[u] = true;
        for (int j = 0; j < vec[u].size(); j++)
        {
            int adjacent = vec[u][j].first;
            int adj_weight = vec[u][j].second;

            if (mst[adjacent] == false && dist[adjacent] > dist[u] + adj_weight)
            {
                dist[adjacent] = dist[u] + adj_weight;
            }
        }
    }

    cout << "Minimum distances(without priority queue) are: " << endl;
    for (int i = 0; i < dist.size(); i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}

struct mycmp
{
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2)
    {
        return p1.second > p2.second;
    }
};

// with priority queue
void dijstra2(vector<pair<int, int>> vec[], int v, int source)
{
    vector<int> dist(v, INT_MAX);
    vector<bool> mst(v, false);

    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycmp> pq;
    pq.push({source, 0});

    for (int i = 0; i < v; i++)
    {
        while (pq.empty() == false && mst[pq.top().first] == true)
        {
            pq.pop();
        }

        pair<int, int> curr = pq.top();
        pq.pop();

        for (int j = 0; j < vec[curr.first].size(); j++)
        {
            int adjacent = vec[curr.first][j].first;
            int adj_weight = vec[curr.first][j].second;

            if (mst[adjacent] == false && dist[adjacent] > dist[curr.first] + adj_weight)
            {
                dist[adjacent] = dist[curr.first] + adj_weight;
                pq.push({adjacent, dist[adjacent]});
            }
        }
    }
    cout << "Minimum distances(priority queue) are: " << endl;
    for (int i = 0; i < dist.size(); i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main()
{
    // int v = 5;
    // vector<pair<int, int>> adj[v];

    // add_edge(adj, 0, 1, 6);
    // add_edge(adj, 0, 3, 1);
    // add_edge(adj, 1, 3, 2);
    // add_edge(adj, 3, 4, 1);
    // add_edge(adj, 1, 4, 2);
    // add_edge(adj, 1, 2, 5);
    // add_edge(adj, 2, 4, 5);

    // int source = 0;

    int v = 5;
    vector<pair<int, int>> adj[v];

    add_edge(adj, 0, 1, 3);
    add_edge(adj, 0, 2, 1);
    add_edge(adj, 1, 2, 7);
    add_edge(adj, 2, 3, 2);
    add_edge(adj, 1, 3, 5);
    add_edge(adj, 1, 4, 1);
    add_edge(adj, 3, 4, 7);

    int source = 2;


    dijstra1(adj, v, source);
    dijstra2(adj, v, source);
    return 0;
}