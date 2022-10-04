// adjacency List show
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

void add_edge(vector<int> vec[], int u, int v)
{
    vec[u].push_back(v);
    vec[v].push_back(u);
}

void show_list(vector<int> vec[], int list_size)
{
    for (int i = 0; i < list_size; i++)
    {
        cout << i << " --> ";
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int v;
    v = 5;
    vector<int> adj[v];

    // adding all edges
    add_edge(adj, 0, 1);
    add_edge(adj, 0, 4);
    add_edge(adj, 1, 3);
    add_edge(adj, 3, 4);
    add_edge(adj, 2, 3);

    cout << "Check Matrix: " << endl;
    show_list(adj, v);
    return 0;
}