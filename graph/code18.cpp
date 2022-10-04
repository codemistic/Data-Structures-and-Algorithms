// Strongly connected components (Kosaraju's algorithm)
// In this code we will be finding strongly connected components in directed connected graphs
// Here when we do observation we find that if we start from sink side of nodes and try to find connected components then we get them right
// but if we start from source side we can never get it cause source side will also include sink as well and not strongly components as well

// So the algo has three steps
// 1. find source to sink side thorugh topological sort
// 2. reverse all the edges
// 3. check from topo sort and print all connected components in one go!

//  so when we find source to sink and reverse edges then source actually becomes sink now and we are traversing from sink side .. also
// connected components stay connected when reversed so we reverse edges

// one doubt can be why cant we just start from sink side without reversing edges .. here there are chances that we will include those which are not
// part of connected components

// example: 0->1 , 1->2 , 1->3, 3->1  .. here topo sort will be 0, 1, 2, 3... when we start from 3 .. connected components will be : 3 0 1 2...
//  which is wrong

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

void add_edge(vector<int> vec[], int u, int v)
{
    vec[u].push_back(v);
}

void topo_sort(vector<int> vec[], int source, vector<bool> &visited, stack<int> &st)
{
    visited[source] = true;
    for (int i = 0; i < vec[source].size(); i++)
    {
        int adjacent = vec[source][i];
        if (visited[adjacent] == false)
        {
            topo_sort(vec, adjacent, visited, st);
        }
    }
    st.push(source);
}

void find_transpose(vector<int> vec[], int v, vector<int> transpose[])
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            int first = i;
            int second = vec[i][j];
            add_edge(transpose, second, first);
        }
    }
}

void dfs(vector<int> transpose[], int source, vector<bool> &visited)
{
    cout << source << " ";
    visited[source] = true;
    for (int i = 0; i < transpose[source].size(); i++)
    {
        int adjacent = transpose[source][i];
        if (visited[adjacent] == false)
        {
            dfs(transpose, adjacent, visited);
        }
    }
}

void kosaraju(vector<int> vec[], int v, vector<int> transpose[])
{
    vector<bool> visited(v, false);
    int source = 0;
    stack<int> st;
    // finding topo sort first
    topo_sort(vec, source, visited, st);

    // finding transpose
    find_transpose(vec, v, transpose);

    // final step of printing connected components ..  we wll do it via dfs
    for (int i = 0; i < visited.size(); i++)
    {
        // making visited vector again false as it is used in topo_sort and it is all true
        visited[i] = false;
    }
    cout << "Printing connected components: " << endl;
    for (int i = 0; i < visited.size(); i++)
    {
        if (visited[i] == false)
        {
            dfs(transpose, i, visited);
            cout << endl;
        }
    }
}

int main()
{
    // int v = 5;
    // vector<int> adj[v], transpose[v];
    // // adding edges now
    // add_edge(adj, 0, 1);
    // add_edge(adj, 1, 2);
    // add_edge(adj, 2, 0);
    // add_edge(adj, 1, 3);
    // add_edge(adj, 3, 4);

    int v = 6;
    vector<int> adj[v], transpose[v];
    // adding edges now
    add_edge(adj, 0, 1);
    add_edge(adj, 1, 2);
    add_edge(adj, 2, 3);
    add_edge(adj, 3, 0);
    add_edge(adj, 3, 4);
    add_edge(adj, 4, 5);
    add_edge(adj, 5, 4);

    kosaraju(adj, v, transpose);
    return 0;
}