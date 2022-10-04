// In this code we will do bridges in graph...

// by bridges we mean any edge .. removal of which creates extra number of graphs components ..
// one simple approach can be we remove each edge and and then check for count of connected components
// this approach will take O(E * (V+E)) (E for count of edges as we have to remove each edge and (V+E) for the function to check count of
// connected components

// second approach is doing this with the concept of discovery time and low time (same as articulation point)
// but in that condition was min[adjacent] >= disc[source] but here it will be min[adjacent] > disc[source]
// as we need to check if some nodes are completely on one side and others on one side .. and if we keep equal conditon then
// that means there is other edge connected to other half and we can't say its a bridge..

// also there is no concept of root condition(there was one in articulation point) cause there we were checking for nodes
// but here it is edge

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

void add_edge(vector<int> vec[], int u, int v)
{
    vec[u].push_back(v);
    vec[v].push_back(u);
}

// dfs_func function gives discovery time and low time for any node...
// here we firstly give (discovery time and low time) to each node according to their finding time
// then whenever we found a node which is already visited before we give its discovery time to all nodes from which this can be reached
// we do it by firsty applying condition where we find a visited node and then we reduce (low time) by calling this min func after recursion
// so when we call min function in recursion we already have minimum for adjacent which we got from elseif condition and we wil further use it now

// note: line 49 will execute recursively then at the end line 61 will update it then line 51 will make further updations

void dfs_func(vector<int> vec[], int source, vector<bool> &visited, vector<int> &disc, vector<int> &low, int &time, int parent)
{
    visited[source] = true;
    disc[source] = low[source] = time;

    time++;

    for (int i = 0; i < vec[source].size(); i++)
    {
        int adjacent = vec[source][i];
        if (visited[adjacent] == false)
        {

            // calling recursion function
            dfs_func(vec, adjacent, visited, disc, low, time, source);
            // after we make low value less for adjacent we call this fucntion so that this can further update it
            low[source] = min(low[source], low[adjacent]);

            if (low[adjacent] > disc[source])
            {
                cout << source << " " << adjacent << endl;
            }
        }
        // when we get visited adjacent we call min function to make low value less...
        else if (visited[adjacent] == true && adjacent != parent)
        {
            low[source] = min(low[source], disc[adjacent]);
        }
    }
}

void bridges(vector<int> vec[], int v)
{
    vector<int> disc(v), low(v);
    vector<bool> visited(v, false);

    int time = 1;

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            dfs_func(vec, i, visited, disc, low, time, -1);
        }
    }
}

int main()
{
    // int v = 7;
    // vector<int> vec[v];

    // // adding edges now
    // add_edge(vec, 0, 1);
    // add_edge(vec, 0, 3);
    // add_edge(vec, 1, 2);
    // add_edge(vec, 1, 4);
    // add_edge(vec, 2, 3);
    // add_edge(vec, 4, 5);
    // add_edge(vec, 4, 6);
    // add_edge(vec, 5, 6);

    // bridges(vec, v);

    int v = 5;
    vector<int> vec[v];

    add_edge(vec, 1, 0);
    add_edge(vec, 0, 2);
    add_edge(vec, 2, 1);
    add_edge(vec, 0, 3);
    add_edge(vec, 3, 4);
    bridges(vec, v);
    return 0;
}