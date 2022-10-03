/*

Topological Sorting in Directed Acyclic graphs

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v,vertex u comes 
before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG ( Directed Acyclic Graph ).

Topological Sorting can be done using both Depth First Search method ( Recursive method ) and Breadth First Search method ( Kahn's Algorithm).
The implementation below is the Depth First Search version.

For Breadth First Search Method you can refer to this site : https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/

Time Complexity : O( V + E )                            V - Number of Vertices in the graph
Space Complexity : O( V )                               E - Number of Edges in the graph


Practice Problem Link : https://practice.geeksforgeeks.org/problems/topological-sort/1
My profile link : https://leetcode.com/abhi__ram/


*/


#include <bits/stdc++.h>
using namespace std;

struct TopologicalSort
{
    int V;
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<bool> present;
    vector<int> ans;

    TopologicalSort(vector<vector<int>> adj, int n){
        this->V = n;
        this->adj = adj;
        visited.resize(n, false);
        present.resize(n, false);
    }

    bool dfs(int i){
        if (!visited[i]){
            visited[i] = true;
            present[i] = true;
            for (int &v : adj[i]){
                if (present[v])
                    return false;
                if (!dfs(v))
                    return false;
            }
            ans.push_back(i);
            present[i] = false;
        }
        return true;
    }

    vector<int> topoSort(){

        bool ok = 1;
        for (int i = 0; i < V; i++){
            if (!visited[i])
                ok &= dfs(i);
            if (!ok)
            {
                ans.push_back(-1);
                return ans;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int32_t main(){

    int V, E;
    cin >> V >> E ;
    vector<vector<int>> adj(V);

    for(int i=0;i<E;i++){
        int u,v,w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    struct TopologicalSort T(adj,V);
    vector<int> ans = T.topoSort();
   
    return 0;
}
