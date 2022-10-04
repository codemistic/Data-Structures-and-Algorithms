// Topological Sort -> DFS
// In DFS type approach we first go till end where there are no more adjacents left that means we can then push them
// and above that we will push vertex which are parents and we will do it with recursion.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

void add_edge(vector<int> vec[], int u, int v)
{
    vec[u].push_back(v);
}

void topo_sort(vector<int> vec[], vector<bool> &visited, int source, stack<int> &s)
{
    cout<<"source: "<<source<<endl;
    visited[source] = true;
    for (int i = 0; i < vec[source].size(); i++)
    {
        int adjacent = vec[source][i];
        if (visited[adjacent] == false)
        {
            topo_sort(vec, visited, adjacent, s);
        }
    }
    s.push(source);
    return;
}

void topo_rec(vector<int> vec[], int v)
{
    vector<bool> visited(v, false);
    stack<int> s;
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            topo_sort(vec, visited, i, s);
        }
    }

    while(s.size() > 0) {
        int curr = s.top();
        s.pop();
        cout<<curr << " ";
    }
    return;
}

int main()
{
    int v;
    v = 4;
    vector<int> vec[v];

    // adding edges from this point
    // add_edge(vec, 0, 1);
    // add_edge(vec, 0, 3);
    // add_edge(vec, 1, 2);
    // add_edge(vec, 2, 4);
    // add_edge(vec, 3, 1);
    // add_edge(vec, 3, 4);

    add_edge(vec, 0, 1);
    // add_edge(vec, 0, 3);
    add_edge(vec, 1, 2);
    add_edge(vec, 1, 3);
    add_edge(vec, 3, 2);
    // add_edge(vec, 3, 4);

    topo_rec(vec, v);

    return 0;
}