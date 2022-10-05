// minimum spanning tree with kruskal algorithm
// In this algorithm we take all the edges and sort them in increasing order of their weights
// them we take an edge and find if adding it leads to any cycle or not
// if it does not form a cycle then we keep it added otherwise we remove it and move on to next one

// for cycle detection we can run a cycle detection algorithm or we can find it with the help of union add and find which will take less
// time complexity than normal cycle detection algorithm

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

struct node
{
    int u, v, weight;
};

bool mycomp(node n1, node n2)
{
    return n1.weight < n2.weight;
}

void add_edge(vector<pair<int, int>> vec[], int u, int v, int weight)
{
    vec[u].push_back({v, weight});
    // vec[v].push_back({u, weight});
}

int find(vector<int> &parent, int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    parent[x] = find(parent, parent[x]);
    return parent[x];
}

void make_union(vector<int> &parent, vector<int> &rank, int a, int b)
{
    int first_parent = find(parent, a);
    int second_parent = find(parent, b);

    if (first_parent == second_parent)
    {
        return;
    }

    if (rank[first_parent] < rank[second_parent])
    {
        parent[first_parent] = second_parent;
    }
    else if (rank[first_parent] > rank[second_parent])
    {
        parent[second_parent] = first_parent;
    }
    else
    {
        parent[first_parent] = second_parent;
        rank[second_parent]++;
    }
}

void kruskal(vector<pair<int, int>> vec[], int v)
{
    vector<int> arr(v), rank(v, 0);
    for (int i = 0; i < v; i++)
    {
        arr[i] = i;
    }
    vector<node> nodes;
    for (int i = 0; i < v; i++)
    {
        int curr = i;
        for (int j = 0; j < vec[curr].size(); j++)
        {
            int adj = vec[curr][j].first;
            int adj_weight = vec[curr][j].second;

            nodes.push_back({curr, adj, adj_weight});
        }
    }
    sort(nodes.begin(), nodes.end(), mycomp);

    int mini_weight = 0;

    for (int i = 0; i < nodes.size(); i++)
    {
        node curr = nodes[i];
        int find_first = find(arr, curr.u);
        int find_sec = find(arr, curr.v);

        if (find_first == find_sec)
        {
            continue;
        }
        else
        {
            make_union(arr, rank, curr.u, curr.v);
            cout << "Connected Edge: " << curr.u << " " << curr.v << " " << curr.weight << endl;
            mini_weight += curr.weight;
        }
    }

    cout << "Minimum Spanning Tree weight: " << mini_weight << endl;
}

int main()
{
    // int v = 6;
    // vector<pair<int, int>> adj[v];

    // // adding edges now
    // add_edge(adj, 0, 2, 6);
    // add_edge(adj, 1, 5, 1);
    // add_edge(adj, 2, 5, 2);
    // add_edge(adj, 2, 3, 5);
    // add_edge(adj, 3, 4, 3);
    // add_edge(adj, 4, 5, 4);

    int v = 9;
    vector<pair<int, int>> adj[v];

    // adding edges now
    add_edge(adj, 0, 1, 4);
    add_edge(adj, 1, 2, 8);
    add_edge(adj, 2, 3, 7);
    add_edge(adj, 3, 4, 9);
    add_edge(adj, 4, 5, 10);
    add_edge(adj, 5, 6, 2);
    add_edge(adj, 6, 7, 1);
    add_edge(adj, 7, 0, 8);
    add_edge(adj, 1, 7, 11);
    add_edge(adj, 3, 5, 14);
    add_edge(adj, 2, 8, 2);
    add_edge(adj, 6, 8, 6);
    add_edge(adj, 7, 8, 7);

    kruskal(adj, v);

    return 0;
}