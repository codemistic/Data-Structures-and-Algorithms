// Shortest Path in DAG (Weighted)
// shortest path in DAG is based on the fact that in DAG we can find topo sort
// and topo sort represents source to sink i.e we will start with a node which does not depend on any other node
// and keep on traversing until we find last node

// here we will start with the most independent node and then find shortest path from this to all its adjacent nodes
// which means that when we reach any node we already covered all nodes which comes before it and we already explored all possible
// possibilities (i.e shortest path)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

void add_edge(vector<pair<int, int>> vec[], int u, int v, int weight)
{
    vec[u].push_back({v, weight});
}

vector<int> topo_sort(vector<pair<int, int>> vec[], int v)
{
    // here we will find topo sort by using bfs code for that
    vector<int> indegree(v, 0);
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            indegree[vec[i][j].first]++;
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

    vector<int> ans;
    while (q.empty() == false)
    {
        int curr = q.front();
        q.pop();

        ans.push_back(curr);
        for (int i = 0; i < vec[curr].size(); i++)
        {
            int adjacent = vec[curr][i].first;
            indegree[adjacent]--;

            if (indegree[adjacent] == 0)
            {
                q.push(adjacent);
            }
        }
    }

    return ans;
}

void shortest_dist(vector<pair<int, int>> vec[], vector<int> &sort_vec, int v, int source)
{
    vector<int> dist(v, INT_MAX);
    dist[source] = 0;

    int pos = -1;

    for (int i = 0; i < sort_vec.size(); i++)
    {

        // cout << sort_vec[i] << " ";
        if (sort_vec[i] == source)
        {
            pos = i;
            break;
        }
    }

    // cout<<"pos: "<<pos<<endl;

    for (int i = pos; i < sort_vec.size(); i++)
    {
        int curr = sort_vec[i];

        // cout << "curr: " << curr << endl;

        for (int j = 0; j < vec[curr].size(); j++)
        {
            int adjacent = vec[curr][j].first;

            // cout << adjacent << endl;

            if (dist[adjacent] > dist[curr] + vec[curr][j].second)
            {
                dist[adjacent] = dist[curr] + vec[curr][j].second;
            }
        }
    }

    cout << "CHECK SHORTEST DISTANCE:" << endl;
    for (int i = 0; i < dist.size(); i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main()
{
    clock_t start = clock();

    // int v = 6;
    // vector<pair<int, int>> adj[v];

    // // adding edges now
    // add_edge(adj, 0, 1, 4);
    // add_edge(adj, 0, 2, 2);
    // add_edge(adj, 1, 3, 10);
    // add_edge(adj, 1, 2, 5);
    // add_edge(adj, 2, 4, 3);
    // add_edge(adj, 4, 3, 4);
    // add_edge(adj, 3, 5, 11);

    // vector<int> sort_vec = topo_sort(adj, v);

    // int source = 1;

    // shortest_dist(adj, sort_vec, v, source);

    int v = 4;
    vector<pair<int, int>> adj[v];

    // adding edges now
    add_edge(adj, 0, 1, 15);
    add_edge(adj, 0, 2, 2);
    add_edge(adj, 2, 3, 3);
    add_edge(adj, 3, 1, 4);

    vector<int> sort_vec = topo_sort(adj, v);

    int source = 0;

    shortest_dist(adj, sort_vec, v, source);

    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;
    // printf("Time measured: %.4f seconds.", elapsed);
    return 0;
}