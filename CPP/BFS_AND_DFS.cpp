#include <bits/stdc++.h>
using namespace std;

int v;  //No. of Vertices

void Add_edge(vector<int> adj[], int a, int b)
{
    adj[a].push_back(b);
}

/************************************* ALGORITHM FOR BREADTH FIRST SEARCH ******************************************************/

// Take the empty queue and bool type array (visit) initialise with FALSE.
// Push the starting node in the queue and set the value TRUE for this node in visited array.
// Pop out the front node of the queue and print the node.
// Push the adjacent node of pop node in queue which are not visited. Set the value TRUE in visited array of adding node.
// Repeat step 3 and 4 until the queue becomes empty.

void bfs(int n, vector<int>adj[])
{
    vector<bool> visit(v,false);
    queue<int> q;
    q.push(n);
    visit[n]=true;
    while(!q.empty())
    {
        n=q.front();
        cout<<n<<" ";
        q.pop();
        for(int i=0;i<adj[n].size();i++)
        {
            if(!visit[adj[n][i]])
            {
                q.push(adj[n][i]);
                visit[adj[n][i]]=true;
            }
        }
    }
}

/************************************* ALGORITHM FOR DEPTH FIRST SEARCH ******************************************************/

// Take the empty stack and bool type array (visit) initialise with FALSE.
// Push the starting node in the stack and set the value TRUE for this node in visited array.
// Pop the top node from the stack and print that node.
// Push the adjacent node of pop node in the stack which is not visited. Set the value TRUE in visited array of adding node.
// Repeat step 3 and 4 until the stack becomes empty.


void dfs(int n, vector<int> adj[])
{
    vector<bool> visit(v,false);
    stack<int> s;
    s.push(n);
    visit[n]=true;
    while(!s.empty())
    {
        n=s.top();
        cout<<n<<" ";
        s.pop();
        for(int i=0;i<adj[n].size();i++)
        {
            if(!visit[adj[n][i]])
            {
                s.push(adj[n][i]);
                visit[adj[n][i]]=true;
            }
        }
    }

}

int main()
{
     cout<<"Enter the no. of vertices : ";
     cin>>v;
     vector<int> adj[v];
     vector<bool> visit(v,false);
     Add_edge(adj,0,1);  
     Add_edge(adj,0,2);  
     Add_edge(adj,1,2);  
     Add_edge(adj,2,0);    
     Add_edge(adj,2,3);  
     Add_edge(adj,3,3); 

    int temp;
    cout<<"Choose the vertex from you want to start traversing : ";
    cin>>temp;
    cout<<"\nBFS traversal is"<<" ";
    bfs(temp,adj);
    cout<<"\nDFS traversal is"<<" ";
    dfs(temp,adj);

 return 0;
}