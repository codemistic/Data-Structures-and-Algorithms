#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m;
int dist[100];
int parent[100];
vector<int> adjList[100];
queue<int> q;

void bfs(int sour)
{
    for(int i=1;i<=n;i++)
    {
        if(n!=1)
        {
            parent[i]=0;
            dist[i]=-1;
        }
    }
    parent[sour]=0;
    dist[sour]=0;
    q.push(sour);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int j=0;j<adjList[x].size();j++)
        {
            int v=adjList[x][j];
            if(parent[v]==0)
            {
                dist[v]=dist[x]+1;
                parent[v]=x;
                q.push(v);
            }
        }
    }
}

int main()
{
    cout<<"Enter Node_";
    cin>>n;
    cout<<"Enter Edges_";
    cin>>m;
    int x,y;
    for(int i=1;i<=m;i++)
    {
        cin>>x;
        cin>>y;
        adjList[x].push_back(y);
    }

    for(int i=1;i<=n;i++)
    {
        cout<<i<<" -->";
        for(int j=0;j<adjList[i].size();j++)
        {
            cout<<adjList[i][j]<<" ";
        }
        cout<<endl;
    }

bfs(1);
for(int i=1;i<=n;i++)
{
    cout<<"\tVertex="<<i;
    cout<<"\tParent="<<parent[i];
    cout<<"\tDistance="<<dist[i];
    cout<<endl;
}
    return 0;
}