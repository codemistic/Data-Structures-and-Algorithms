#include<bits/stdc++.h>
using namespace std;
class Edge{
   int v;
   int wt;
   public:
   Edge(int v, int wt){
       this->v=v;
       this->wt=wt;
   }
   void dijkstras(vector<vector<Edge>> &graph, int src) {
     vector<int> dist(graph.size(), INT_MAX);
     dist[src] = 0;
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
     pq.push({0,src});
     while(!pq.empty()){
       int u=pq.top().second;
         pq.pop();
       vector<Edge> edges=graph[u];
       for(auto edge: edges){
        if(dist[edge.v]>dist[u]+edge.wt)
        {
            dist[edge.v]=dist[u]+edge.wt;
            pq.push({dist[edge.wt], edge.v});
        }
       }
     }
     for(auto d: dist)
       cout<<d<<" ";
   }
};
int main(){
    vector<vector<Edge>> graph(6);
    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));
    graph[1].push_back(Edge(2,1));
    graph[1].push_back(Edge(3,7));
    graph[2].push_back(Edge(4,3));
    graph[3].push_back(Edge(5,1));
    graph[4].push_back(Edge(5,5));
    graph[4].push_back(Edge(3,2));
    Edge e(0,0);
    e.dijkstras(graph, 0);
}