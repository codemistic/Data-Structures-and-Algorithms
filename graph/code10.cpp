// Detect cycle in directed graph --> DFS
// here we find that if in stack call of recursion of dfs there is a back edge
// i.e. if a number finds that one if its adjacent is already visited and active in stack then that means that there is a cycle

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

void add_edge(vector<int> vec[], int u, int v)
{
    vec[u].push_back(v);
}

bool dfs(vector<int> vec[], vector<bool> &visited, vector<bool> &recst, int source)
{
    visited[source] = true;
    recst[source] = true;
    for (int i = 0; i < vec[source].size(); i++)
    {
        int adjacent = vec[source][i];
        if (visited[adjacent] == false)
        {
            if (dfs(vec, visited, recst, adjacent) == true)
            {
                return true;
            }
        }
        else if (visited[adjacent] == true && recst[adjacent] == true)
        {
            return true;
        }
    }
    recst[source] = false;
    return false;
}

bool dfs_rec(vector<int> vec[], int v)
{
    vector<bool> visited(v, false);
    vector<bool> recst(v, false);
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            if (dfs(vec, visited, recst, i))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int v;
    v = 6;
    vector<int> vec[v];

    // adding edges from this point

    // add_edge(vec, 0, 1);
    // add_edge(vec, 1, 2);
    // add_edge(vec, 2, 3);
    // add_edge(vec, 2, 4);
    // add_edge(vec, 4, 5);
    // add_edge(vec, 5, 1);

    add_edge(vec, 0, 1);
    add_edge(vec, 2, 3);
    add_edge(vec, 3, 4);
    add_edge(vec, 4, 5);
    add_edge(vec, 5, 1);

    if (dfs_rec(vec, v))
    {
        cout << "There is a cycle in the graph!!" << endl;
    }
    else
    {
        cout << "There isnt a cycle in the graph!!" << endl;
    }
    return 0;
}