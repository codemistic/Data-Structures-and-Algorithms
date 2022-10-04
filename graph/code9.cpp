// Detect cycle in a directed graph using BFS
// here we will use topo_sort in topo sort we reduce indegrees but in cycle.. for all the vertex in
// the cycle the indegree will never be zero ... we can find out from there

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

void add_edge(vector<int> vec[], int u, int v)
{
    vec[u].push_back(v);
}

bool topo_sort(vector<int> vec[], int v)
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
    int count = 0;
    while (q.empty() == false)
    {
        int curr = q.front();
        q.pop();

        count++;
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
    return count == v;
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
    add_edge(vec, 4, 3);

    if (topo_sort(vec, v))
    {
        cout << "No cycle " << endl;
    }
    else
    {
        cout << "there is a cycle" << endl;
    }

    return 0;
}