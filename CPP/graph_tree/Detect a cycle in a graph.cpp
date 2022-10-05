#include<iostream>
#include<list>
#include<cstring>
using namespace std;

class Graph{
int V;
list<int> *adj;

bool isCyclicHelper(int s,bool *visited,bool *RStack){
        if(visited[s]==false){
                visited[s] = true;
                rStack[s] = true;

        for(auto it=adj[s].begin();it!=adj[s].end();it++){
                if(!visited[*it]&&isCyclicHelper(*it,visited,rStack)){
                    return true;
                }
                else if(rStack[*it]){
                    return true;
                }
            }

        }
RStack[s]=false;
return false;
}


public:
   Graph(int V){
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int u,int v){
        adj[u].push_back(v);

    }

    bool isCyclic(){
        bool *visited = new bool[V];
        bool *rStack = new bool[V];

        memset(visited,false,sizeof(false));
        memset(rStack,false,sizeof(false));

        //This works if there is a single DFS forest. Otherwise use a for loop.
        if(isCyclicHelper(0,visited,rStack)){
            return true;
        }
        else{
            return false;
        }
    }

};

int main(){

 Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;

return 0;
}
