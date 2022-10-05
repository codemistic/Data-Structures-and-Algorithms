// Minimum Spanning tree
// Basically it is forming a tree kind of structure where there are v vertices and v-1 edges and every node is connected to other node
// directly or indirectly
// In prims algorithm, we make two sets of (included in MST) & (Not included in MST)
// then we take first node include in MST and then take weight of all edges connected to it and not included in MST and then find minimum
// of them and making this move again and again till we include (v-1) edges
// also graph should be connected weighted undirected

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

void add_edge(vector<pair<int, int>> vec[], int u, int v, int weight)
{
    vec[u].push_back({v, weight});
    vec[v].push_back({u, weight});
}

// this algo is without using priority queue
void prims_algo1(vector<pair<int, int>> vec[], int v)
{
    // one array for checking whether included in mst or not
    // second array for distance computation

    vector<bool> mst(v, false);
    vector<int> dist(v, INT_MAX);

    // int ans = 0;

    int source = 0;
    dist[source] = 0;

    for (int i = 0; i <= v - 1; i++)
    {
        // finding minimum edge which includes one non added node
        int pos = -1; // index of node which is not yet included in MST and is minimum

        // cout << "dist: array: " << endl;
        // for (int j = 0; j < dist.size(); j++)
        // {
        //     cout << dist[j] << " ";
        // }
        // cout<<"mist array: "<<endl;
        // for(int j = 0;j<mst.size();j++) {
        //     cout<<mst[j]<<" ";
        // }
        // cout<<endl;
        // cout << endl;
        for (int j = 0; j < dist.size(); j++)
        {
            if ((dist[j] < dist[pos] && mst[j] == false) || pos == -1 && mst[j] == false)
            {
                pos = j;
                // cout<<"pos: "<<pos<<" ";
            }
        }

        mst[pos] = true;

        // cout<<endl;

        // ans += dist[pos];
        for (int j = 0; j < vec[pos].size(); j++)
        {
            int adjacent = vec[pos][j].first;

            if (dist[adjacent] > vec[pos][j].second && mst[adjacent] == false)
            {
                dist[adjacent] = vec[pos][j].second;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < dist.size(); i++)
    {
        ans += dist[i];
    }
    cout << "final answer from algo 1 is : " << ans << endl;
}

struct mycmp
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second;
    }
};

void prims_algo2(vector<pair<int, int>> vec[], int v)
{
    vector<bool> mst(v, false);
    vector<int> dist(v, INT_MAX);

    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycmp> pq;
    pq.push({0, 0});

    int ans = 0;

    int count = 0;
    for (int i = 0; i < v; i++)
    {
        while (pq.empty() == false && mst[pq.top().first] == true)
        {
            pq.pop();
        }
        pair<int, int> curr = pq.top();
        pq.pop();

        // cout << "curr.first() " << curr.first << " curr.second() " << curr.second << endl;

        mst[curr.first] = true;
        ans += curr.second;
        for (int j = 0; j < vec[curr.first].size(); j++)
        {
            int adjacent = vec[curr.first][j].first;
            if (mst[adjacent] == false && dist[adjacent] > vec[curr.first][j].second)
            {
                pq.push({adjacent, vec[curr.first][j].second});
            }
        }
    }
    cout << "Final answer from algo 2 is : " << ans << endl;
}

int main()
{
    int v = 7;
    vector<pair<int, int>> adj[v];

    // adding all edges now
    add_edge(adj, 0, 1, 7);
    add_edge(adj, 0, 3, 5);
    add_edge(adj, 1, 3, 9);
    add_edge(adj, 1, 2, 8);
    add_edge(adj, 1, 4, 7);
    add_edge(adj, 2, 4, 5);
    add_edge(adj, 3, 4, 15);
    add_edge(adj, 3, 5, 6);
    add_edge(adj, 4, 5, 8);
    add_edge(adj, 4, 6, 9);
    add_edge(adj, 5, 6, 11);

    // int v = 5;
    // vector<pair<int, int>> adj[v];

    // add_edge(adj, 0, 1, 5);
    // add_edge(adj, 0, 2, 2);
    // add_edge(adj, 1, 2, 4);
    // add_edge(adj, 1, 4, 1);
    // add_edge(adj, 2, 3, 6);
    // add_edge(adj, 4, 3, 3);

    prims_algo1(adj, v);

    prims_algo2(adj, v);

    return 0;
}