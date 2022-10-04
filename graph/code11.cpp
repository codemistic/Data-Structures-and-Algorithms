// Topological Sort -> Kahn's Based algorithm --> BFS
// Kahn algorithm is based on removing the vertex which do not depend on any other vertex i.e having 0 indegree
// and then keep on removing and finding the sequence.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

void add_edge(vector<int> vec[], int u, int v)
{
    vec[u].push_back(v);
}

void topo_sort(vector<int> vec[], int v)
{
    vector<int> indegree(v, 0);
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            int adjacent = vec[i][j];
            indegree[adjacent]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    cout << "TOPOLOGICAL SORT: " << endl;
    while (q.empty() == false)
    {
        int curr = q.front();
        q.pop();

        cout << curr << " ";
        for (int i = 0; i < vec[curr].size(); i++)
        {
            int adjacent = vec[curr][i];

            indegree[adjacent]--;
            if (indegree[adjacent] == 0)
            {
                q.push(adjacent);
            }
        }
    }
    return;
}

int main()
{
    int v;
    v = 5;
    vector<int> vec[v];

    // adding edges from this point
    add_edge(vec, 0, 1);
    add_edge(vec, 0, 3);
    add_edge(vec, 1, 2);
    add_edge(vec, 2, 4);
    add_edge(vec, 3, 1);
    add_edge(vec, 3, 4);

    topo_sort(vec, v);

    return 0;
}