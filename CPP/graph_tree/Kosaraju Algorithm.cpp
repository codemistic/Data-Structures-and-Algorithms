// Kosaraju Algorithm - By Sameer Aggrawal

// Similar to topological sort function (dfs)
void dfs(int node,vector<int> adj[],vector<bool> &visited,stack<int> &stk)
{
    visited[node] = true;
    
    for(auto child: adj[node])
    {
        if(!visited[child])
        {
            dfs(child,adj,visited,stk);
        }
    }
    
    stk.push(node);
}
	
void dfsRec(int node,vector<int> g[],vector<bool> &visited)
{
    visited[node]=true;
    
    for(auto child: g[node])
    {
        if(!visited[child])
        {
            dfsRec(child,g,visited);
        }
    }
    
    return;
}
	
//Function to find number of strongly connected components in the graph.
int kosaraju(int V, vector<int> adj[])
{
    int i,j;
    
    stack<int> stk;
    
    vector<int> result;
    vector<bool> visited(V,false);
    
    for(i=0;i<V;i++)
    {
        if(!visited[i])
        {
            dfs(i,adj,visited,stk);
        }
    }
    
    while(!stk.empty())
    {
        result.push_back(stk.top());
        stk.pop();
    }
    
    vector<int> g[V];
    
    for(i=0;i<V;i++)
    {
        for(auto x: adj[i])
        {
            g[x].push_back(i);
        }
    }
    
    for(i=0;i<V;i++) visited[i]=false;
    
    int cnt=0;
    
    for(i=0;i<V;i++)
    {
        int node=result[i];
        if(!visited[node])
        {
            cnt++;
            dfsRec(node,g,visited);
        }
    }
    
    return cnt;
}
