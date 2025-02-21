// // Program to find "Least Common Ancestor" of two nodes by "Binary Lifting Technique"

// #include <bits/stdc++.h>
// using namespace std;

// int n, l, timer;
// vector<vector<int>> adj;
// vector<int> tin, tout;
// vector<vector<int>> up;
 
// void dfs(int v, int p)
// {
//     tin[v] = ++timer;
//     up[v][0] = p;
//     for (int i = 1; i <= l; ++i)
//         up[v][i] = up[up[v][i-1]][i-1];
 
//     for (int u : adj[v]) {
//         if (u != p)
//             dfs(u, v);
//     }
 
//     tout[v] = ++timer;
// }
 
// bool is_ancestor(int u, int v)
// {
//     return tin[u] <= tin[v] and tout[u] >= tout[v];
// }
 
// int lca(int u, int v)
// {
//     if (is_ancestor(u, v))
//         return u;
//     if (is_ancestor(v, u))
//         return v;
//     for (int i = l; i >= 0; --i) {
//         if (!is_ancestor(up[u][i], v))
//             u = up[u][i];
//     }
//     return up[u][0];
// }
 
// void preprocess(int root) {
//     tin.resize(n);
//     tout.resize(n);
//     timer = 0;
//     l = ceil(log2(n));
//     up.assign(n, vector<int>(l + 1));
//     dfs(root, root);
// }
 
// void solve(){
//     int q;
//     cin>>n>>q;
//     adj.resize(n + 1);
//     for(int i = 1;i < n;i++){
//         int x;
//         cin>>x;
//         x--;
//         adj[x].push_back(i);
//         adj[i].push_back(x);
//     }
//     preprocess(0);
//     while(q--){
//         int x, y;
//         cin>>x>>y;
//         x--;y--;
//         int ans = lca(x, y);
//         cout<<ans + 1<<endl;
//     }
// }
// int main()
// {
//     solve();
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int n, l, timer;
vector<vector<int>> adj;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;

    for (int i = 1; i <= l; ++i) {
        if (up[v][i - 1] != -1)
            up[v][i] = up[up[v][i - 1]][i - 1];
        else
            up[v][i] = -1;
    }

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;

    for (int i = l; i >= 0; --i) {
        if (up[u][i] != -1 && !is_ancestor(up[u][i], v))
            u = up[u][i];
    }

    return up[u][0];
}

void preprocess(int root) {
    tin.assign(n, 0);
    tout.assign(n, 0);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1, -1));
    dfs(root, root);
}

void solve() {
    int q;
    cin >> n >> q;
    adj.assign(n, vector<int>());

    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        x--;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    preprocess(0);

    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << lca(x - 1, y - 1) + 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
