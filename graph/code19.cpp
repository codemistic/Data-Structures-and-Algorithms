// Articulation Point

// In this code, we will see articulation point .. articulation point is point .. removal of which makes 2 or more components
// one easiest way to handle this would be removing each vertex and count connected components for it.. it takes O(E * (v+E)) time

// now our approach is discovery time and min time .. discovery time refers to time when it was discovered and min time refers to time
// min discovery time it can reach or more to say which min ancestor it can reach in discovery tree..

// now for any child v of any node u if min[v] >= dis[u] then that node is articulation point .. that is cause if min[v] is greater
// than discovery time of that node means any child of this node cant reach ancestor and removing this node will definitely convert tree into
// two parts .. but if any child can reach ancestor means even if we remove this node child will still be attached to ancestor and removing
// this node wont do any good so it is not an articulation point

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

void add_edge(vector<int> vec[], int u, int v)
{
    vec[u].push_back(v);
    vec[v].push_back(u);
}

// dist_minm function gives discovery time and low time for any node...
// here we firstly give (discovery time and low time) to each node according to their finding time
// then whenever we found a node which is already visited before we give its discovery time to all nodes from which this can be reached
// we do it by firsty applying condition where we find a visited node and then we reduce (low time) by calling this min func after recursion
// so when we call min function in recursion we already have minimum for adjacent which we got from elseif condition and we wil further use it now

// note: line 48 will execute recursively then at the end line 60 will update it then line 50 will make further updations
void dist_minm(vector<int> vec[], int source, vector<bool> &visited, vector<int> &disc, vector<int> &low, int &time, int parent,
               vector<bool> &isap)
{
    visited[source] = true;
    disc[source] = low[source] = time;
    time++;

    int children = 0;

    for (int i = 0; i < vec[source].size(); i++)
    {
        int adjacent = vec[source][i];
        if (visited[adjacent] == false)
        {
            children++;
            // calling recursion function
            dist_minm(vec, adjacent, visited, disc, low, time, source, isap);
            // after we make low value less for adjacent we call this fucntion so that this can further update it
            low[source] = min(low[source], low[adjacent]);

            if (low[adjacent] >= disc[source] && parent != -1)
            {
                isap[source] = true;
            }
        }
        // when we get visited adjacent we call min function to make low value less...
        else if (visited[adjacent] == true && adjacent != parent)
        {
            low[source] = min(disc[adjacent], low[source]);
        }
    }
    // we separately check for root node as even if nodes ends at node there is no prior node from which we can say that it made two parts
    // so we check for children of this node and by children we means that children which are not reachable from each other directly .. they
    // firstly have to go through root itself..
    if (parent == -1 && children > 1)
    {
        isap[source] = true;
    }
}

void arti_point(vector<int> vec[], int v)
{
    vector<bool> visited(v, false), isap(v, false);
    vector<int> disc(v), low(v);

    int time = 1;

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            dist_minm(vec, i, visited, disc, low, time, -1, isap);
        }
    }

    cout << "All articulation points: " << endl;
    for (int i = 0; i < isap.size(); i++)
    {
        if (isap[i] == true)
        {
            cout << i << " ";
        }
    }
    cout << endl;

    // cout << "disc time: " << endl;
    // for (int i = 0; i < disc.size(); i++)
    // {
    //     cout << disc[i] << " ";
    // }

    // cout << endl;
    // cout << "low time: " << endl;
    // for (int i = 0; i < low.size(); i++)
    // {
    //     cout << low[i] << " ";
    // }
    // cout << endl;
}

int main()
{
    int v = 7;
    vector<int> vec[v];

    // adding edges now
    add_edge(vec, 0, 1);
    add_edge(vec, 1, 2);
    add_edge(vec, 2, 3);
    add_edge(vec, 0, 3);
    add_edge(vec, 1, 4);
    add_edge(vec, 4, 5);
    add_edge(vec, 5, 6);
    add_edge(vec, 4, 6);

    arti_point(vec, v);
    return 0;
}