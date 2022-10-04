class Solution {
public:
    bool bfs(vector<vector<int>> graph, vector<int> &vis, int src)
    {
        queue<int> q;
        q.push(src);
        int clr = 0;
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                int vrt = q.front();
                q.pop();
                if(vis[vrt]!=-1)
                {
                    if(clr!=vis[vrt])
                        return false;
                    continue;
                }
                vis[vrt]=clr;
                for(int j=0; j<graph[vrt].size(); j++)
                {
                    if(vis[graph[vrt][j]]==-1)
                    q.push(graph[vrt][j]);
                }
            }
            clr = (clr+1)%2;
        }
        return true;;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(),-1);
        for(int i=0; i<graph.size(); i++)
        {
            if(vis[i]==-1 and !bfs(graph, vis, i))
                return false;
        }
        return true;
    }
};
