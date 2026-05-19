// Bellman ford algorithm
// It basically finds after the ith iteration the shortest distance from src to every other node
// and hence promises to find the shortest distance to a node j with atmost i lengths or i-1 stops
// after the ith iteration

// Proof is quite simple though:
//  Consider an arbitrary vertex a to which there is a path from the starting vertex v, and consider a shortest path to it(p0=v,p1,,,,pk=a). Before the first phase, the shortest path to the vertex p0=v  was found correctly. During the first phase, the edge (p0,p1) has been checked by the algorithm, and therefore, the distance to the vertex p1 was correctly calculated after the first phase. Repeating this statement k times, we see that after kth phase the distance to the vertex pk=a gets calculated correctly, which we wanted to prove.

// Initially 0th and 1st versions are same

// dis 0th version contains distances to all veritces after jth iteration that  is having at max j edges
// For full bellman ford just use k=n-1

// Maintaining a parent array for full bellman ford to retrieve cycle




int par[n + 1];
memset(par, -1, sizeof(par));
int dis[n + 1][2];
for (int i = 1; i <= n; i++)
    dis[i][0] = 1e9, dis[i][1] = 1e9;
dis[src][0] = 0;
dis[src][1] = 0;


for (int j = 1; j <= k; j++)
{
    for (auto i : edges)
    {
        if (dis[i[1]][1] > dis[i[0]][0] + i[2])
        {
            dis[i[1]][1] = dis[i[0]][0] + i[2];
            par[i[1]] = i[0];
        }
    }
    for (int i = 0; i < n; i++)
        dis[i][0] = dis[i][1];
}





// Printing parent
vector<int> path;
int t = dest;
for (int cur = t; cur != -1; cur = par[cur])
    path.push_back(cur);
reverse(path.begin(), path.end());

for (int i = 0; i < path.size(); ++i)
    cout << path[i] << ' ';




bool neg_cycle_found = 0;
int node = -1;
// Detection of negative cycle
for (auto i : edges)
{
    if (dis[i[1]][1] > dis[i[0]][0] + i[2])
    {
        neg_cycle_found = 1;
        node = i[1];
    }
}



// Printing negative cycle
if (neg_cycle_found)
{
    int y = node;
    for (int i = 0; i < n; ++i) // It guarantees that after n iterations we would definitely be present
        y = par[y];             // at any node insice cycle as max distance from any node in cycle to
                    // max farthest node could be n-1 only.




    vector<int> path;
    for (int cur = y;; cur = par[cur])
    {
        path.push_back(cur);
        if (cur == y && path.size() > 1)
            break;
    }
    reverse(path.begin(), path.end());

    cout << "Negative cycle: ";
    for (int i = 0; i < path.size(); ++i)
        cout << path[i] << ' ';
}
