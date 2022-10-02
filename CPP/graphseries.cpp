#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool cycleBFS(int node, vector<int> &vis, vector<int> arr[])
{
	queue<pair<int, int>> q;
	q.push({node, -1});
	vis[node] = 1;
	while (!q.empty())
	{
		int n = q.front().first;
		int p = q.front().second;
		q.pop();
		for (auto i : arr[n])
		{
			if (vis[i] == 0)
			{
				vis[i] = 1;
				q.push({i, n});
			}
			else
			{
				if (i != p)
					return true;
			}
		}
	}
	return false;
}

bool cycleDFS(int node, int parent, vector<int> &vis, vector<int> arr[])
{
	vis[node] = 1;
	for (auto i : arr[node])
	{
		if (!vis[i])
		{
			if (cycleDFS(i, node, vis, arr))
				return true;
		}
		else
		{
			if (i != parent)
				return true;
		}
	}

	return false;
}

void bfs(int node, vector<int> &vis, vector<int> arr[], vector<int> &ans)
{
	queue<int> q;
	q.push(node);
	vis[node] = 1;
	while (!q.empty())
	{
		int f = q.front();
		q.pop();
		ans.push_back(f);
		for (auto i : arr[f])
		{
			if (!vis[i])
			{
				vis[i] = 1;
				q.push(i);
			}
		}
	}
}

void dfs(int node, vector<int> &vis, vector<int> arr[], vector<int> &ans)
{
	vis[node] = 1;
	ans.push_back(node);
	for (auto i : arr[node])
	{
		if (!vis[i])
		{
			vis[i] = 1;
			dfs(i, vis, arr, ans);
		}
	}
}

bool bipertiteBFS(int n, vector<int> &color, vector<int> arr[])
{
	queue<int> q;
	q.push(n);
	color[n] = 1;
	while (!q.empty())
	{
		int front = q.front();
		q.pop();
		for (auto i : arr[n])
		{
			if (color[i] == -1)
			{
				color[i] = 1 - color[n];
				q.push(i);
			}
			else
			{
				if (color[i] == color[n])
					return false;
			}
		}
	}

	return true;
}

bool bipertiteDFS(int n, vector<int> &color, vector<int> arr[])
{
	if (color[n] == -1)
		color[n] = 1;
	for (auto i : arr[n])
	{
		if (color[i] == -1)
		{
			color[i] = 1 - color[n];
			if (!bipertiteDFS(i, color, arr))
				return false;
		}
		else
		{
			if (color[i] == color[n])
				return false;
		}
	}
	return true;
}

bool cycleDirectedDFS(int n, vector<int> &vis, vector<int> &dfsvis, vector<int> arr[])
{
	vis[n] = 1;
	dfsvis[n] = 1;

	for (auto i : arr[n])
	{
		if (vis[i] == 0)
		{
			if (cycleDirectedDFS(i, vis, dfsvis, arr))
				return true;
		}
		else
		{
			if (dfsvis[i])
				return true;
		}
	}

	dfsvis[n] = 0;
	return false;
}

void findTopoSortDFS(int node, vector<int> arr[], stack<int> &s, vector<int> &vis)
{
	vis[node] = 1;

	for (auto i : arr[node])
	{
		if (!vis[i])
		{
			findTopoSortDFS(i, arr, s, vis);
		}
	}

	s.push(node);
}

vector<int> topoSortDFS(vector<int> arr[], int n)
{
	stack<int> s;
	vector<int> vis(n, 0);
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			findTopoSortDFS(i, arr, s, vis);
		}
	}

	vector<int> ans;
	while (!s.empty())
	{
		ans.push_back(s.top());
		s.pop();
	}

	return ans;
}

// BFS (Kahn's Algorithm)
vector<int> topoSortBFS(vector<int> arr[], int n)
{
	queue<int> q;
	vector<int> inorder(n, 0);

	for (int i = 0; i < n; i++)
	{
		for (auto it : arr[i])
		{
			inorder[it]++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (inorder[i] == 0)
			q.push(i);
	}
	int count = 0; // this is used to find cycle in graph
	vector<int> ans;
	while (!q.empty())
	{
		int front = q.front();
		q.pop();
		count++;
		ans.push_back(front);
		for (auto i : arr[front])
		{
			inorder[i]--;
			if (inorder[i] == 0)
				q.push(i);
		}
	}

	if (count == n)
	{
		// this means that our graph does not contain a cycle
		cout << "Graph does not contain a cycle";
	}
	else
	{
		// this means that our graph contains a cycle
		cout << "Graph contains a cycle";
	}

	return ans;
}

int shortestPathUndirectedBFS(vector<int> arr[], int n, int source, int destination)
{
	queue<int> q;
	vector<int> distance(n, INT_MAX);
	distance[source] = 0;
	q.push(source);
	while (!q.empty())
	{
		int front = q.front();
		q.pop();
		for (auto i : arr[front])
		{
			distance[i] = min(distance[front] + 1, distance[i]);
			q.push(i);
		}
	}

	// now my distance array has shortest distance from source to every node.
	return distance[destination];
}

// This function is customized for the "shortestPathDAG" fuction
void findTopoSortDFS2(int node, vector<pair<int, int>> arr[], stack<int> &s, vector<int> &vis)
{
	vis[node] = 1;
	for (auto i : arr[node])
	{
		if (!vis[i])
		{
			findTopoSortDFS2(i.first, arr, s, vis);
		}
	}
	s.push(node);
}

// shortest path in weighted DAG(Directed Acyclic Graph)
void shortestPathDAG(vector<pair<int, int>> arr[], int n, int source)
{
	stack<int> s;
	vector<int> vis(n, 0);
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			findTopoSortDFS2(i, arr, s, vis);
		}
	}

	vector<int> distance(n, INT_MAX);
	distance[source] = 0;
	while (!s.empty())
	{
		int temp = s.top();
		s.pop();

		if (distance[temp] != INT_MAX)
		{
			for (auto i : arr[temp])
			{
				distance[i.first] = min(distance[i.first], distance[temp] + i.second);
			}
		}
	}

	for (auto i : distance)
	{
		if (i == INT_MAX)
		{
			cout << "This node is not reachable";
		}
		else
			cout << i << " ";
	}
}

//shortest path in weighted undirected graph
void dijkstrasAlgorithm(vector<int,int>arr[],int n,int source){
	vector<int>dis(n,INT_MAX);
	vector<int>path(n);
	//min priority queue
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>q;
	dis[source]=0;
	q.push({0,source});
	while(!q.empty()){
		pair<int,int>top=q.top();
		int prev=top.second;
		int weight=top.first;
		q.pop();
		for(auto i:arr[prev]){
			if(dis[i.first] > dis[prev]+i.second){
				dis[i]=dis[prev]+i.second;
				path[i.first]=prev;// this line is optional and tells you the shortest path elements 
				q.push({dis[i.first],i.first});
			}
		}
	}

	for(int i:dis)cout<<i<<" ";
}

//for minimum spanning tree -->	BRUTE FORCE O(n^2);
void primsAlogrithm(vector<int,int>arr[],int n){
	int key[n],parent[n];
	bool mst[n];
	for(int i=0;i<n;i++){
		key[i]=INT_MAX;
		parent[i]=-1;
		mst[i]=false;
	}

	key[0]=0;
	parent[0]=-1;

	for(int count=0;count<n-1;count++){
		int min=INT_MAX,prev;
		
		//this loop finds the minimum value in key array i.e. edge with minimum weight
		for(int i=0;i<n;i++){
			if(mst[i]==false && key[i]<min){
				min=key[i],prev=i;
			}
		}
		//marks the minimum value true in mst array
		mst[prev]=true;
		
		//looping in the adjecent nodes of the perv node
		for(auto i:arr[prev]){
			int node=i.first;
			int weight=i.second;
			if(mst[node]==false && weight < key[node]){
				parent[node]=prev;
				key[node]=weight;
			}
		}
	}

	for(int i=0;i<n;i++){
		cout<<parent[i]<<"--"<<i<<endl;
	}
}

//for minimum spanning tree --> Efficent approch O((N+E)logn);
void primsAlgo(vector<int,int>arr[],int n){
	int key[n],parent[n];
	bool mst[n];
	for(int i=0;i<n;i++){
		key[i]=INT_MAX;
		parent[i]=-1;
		mst[i]=false;
	}

	//using min priority queue
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>q;

	key[0]=0;
	parent[0]=-1;
	//in pair first value is weight and second value is node/index.
	q.push({0,0});

	for(int count=0;count<n-1;count++){
		int prev=q.top().second;
		q.pop();
		//marks the minimum value true in mst array
		mst[prev]=true;
		
		//looping in the adjecent nodes of the perv node
		for(auto i:arr[prev]){
			int node=i.first;
			int weight=i.second;
			if(mst[node]==false && weight < key[node]){
				parent[node]=prev;
				key[node]=weight;
				q.push({weight,node});
			}
		}
	}

	for(int i=0;i<n;i++){
		cout<<parent[i]<<"--"<<i<<endl;
	}
}

//structure for kruskals algorithm and bellmenford algorithm
struct node{
	int u;//first node
	int v;// second node
	int wt;// weight between the nodes

	node(int first,int second,int weight){
		u=first;
		v=second;
		wt=weight;
	}
};

//comparator for sorting vector of edges structure
bool comp(node a,node b){
	return a.wt<b.wt;
}

//function for union of two nodes in the set kruskalsalgo
void unionn(int u,int v,vector<int>&parent,vector<int>&rank){
	u=findpair(u,parent);
	v=findpair(v,parent);

	if(rank[u]<rank[v]){
		parent[u]=v;
	}else if(rank[v]<rank[u]){
		parent[v]=u;
	}else{
		parent[v]=u;
		rank[u]++;
	}
}

//function to find the parent of the node in the set kruskalsalgo
int findpair(int n,vector<int>&parent){
	if(parent[n]==n)return n;

	return parent[n]= findpair(parent[n],parent);
}

void kruskalsAlgo(){
	int n,m;
	cin>>n>>m;
	vector<node>edges;
	for(int i=0;i<m;i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		edges.push_back(node(u,v,wt));
	}

	sort(edges.begin(),edges.end(),comp);
	vector<int>parent(n);
	vector<int>rank(n,0);

	for(int i=0;i<n;i++){
		parent[i]=i;
	}

	int cost=0;
	vector<pair<int,int>>mst;//minimum spanning tree
	for(auto it : edges){
		if(findpair(it.u,parent) !=findpair(it.v,parent)){
			cost+=it.wt;
			mst.push_back({it.u,it.v});
			unionn(it.u,it.v,parent,rank);
		}
	}

	cout<<cost<<endl;
}

void bridgeInGraph(int node,int parent,int& timer,vector<int>&vis,vector<int>&low,vector<int>&in,vector<int>arr[]){
	vis[node]=1;
	low[node]=in[node]=timer;
	timer++;

	for(auto it : arr[node]){
		if(it==parent)continue;
		if(vis[it]==1){
			low[node]=min(low[node],in[it]);
		}else{
			bridgeInGraph(it,node,timer,vis,low,in,arr);
			//after dfs call we backtrack
			//if in[node] value is smaller than low[it] then it is an bridge edge.
			//how? because if in[node] is smaller than it means that "it" is not 
			//connect to any ansistor and does not have any other path to reach.
			//if if[node] is greater that means "it" is connect to the ansistor so it has more paths to reach it.
			if(in[node]<low[it]){
				cout<<node<<" - "<<it<<" is a bridge";
			}
		}
	}
}	

//shortest path in a graph with -ve weights 
void bellmenFord(int source){
	int n,m;
	cin>>n>>m;
	vector<node>edges;
	for(int i=0;i<m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		edges.push_back(node(x,y,w));
	}

	vector<int>distance(n,INT_MAX);
	distance[source]=0;

	//relaxing N-1 times every edge
	for(int i=0;i<=n-1;i++){
		for(auto it:edges){
			if(distance[it.v]>distance[it.u]+it.w){
				distance[it.v]=distance[it.u]+it.w;
			}
		}
	}

	int flag=0;
 
	//deceting negative cycle by relaxing one more time i.e Nth time
	for(auto it:edges){
		if(distance[it.v]>distance[it.u]+it.w){
			cout<<"Negative cycle";
			flag=1;
			break;
		}
	}

	if(flag==0){
		for(int i=0;i<n;i++){
			cout<<distance[i]<<" ";
		}
	}
}


int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> arr[n + 1];
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
	vector<int> ans;
	int color[n + 1];				  // for bipartite graph
	memset(color, -1, sizeof(color)); // for bipartite graph
	vector<int> vis(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			if (cycleDFS(i, -1, vis, arr))
				cout << true;
		}
	}

	for (auto i : ans)
		cout << i << " ";
	return 0;
}