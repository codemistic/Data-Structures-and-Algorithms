//Program to check for articulation points of a graph in Java
import java.util.ArrayList;
public class ArticulationPoint {
    public static ArrayList<Integer> articulationPoints(int V, ArrayList<ArrayList<Integer>> adjacencyList){
        boolean[] vis = new boolean[V];
        int[] lowestTime = new int[V];
        int[] seqTime = new int[V];
        boolean[] isArticulation = new boolean[V];

        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                dfs(adjacencyList, i, -1, vis, lowestTime, seqTime, 0, isArticulation);
            }
        }
        ArrayList<Integer> artPoints = new ArrayList<>();

        for(int i = 0 ; i < V ; i++){
            if(isArticulation[i]) artPoints.add(i);
        }
        return artPoints;
    }
    private static void dfs(ArrayList<ArrayList<Integer>> adj, int vertex, int parent, boolean[] vis, int[] lowestTime, int[] seqTime, int time, boolean[] isArticulation){
        vis[vertex] = true;
        lowestTime[vertex] = seqTime[vertex] = time++;
        int children = 0;
        for(Integer neighbour : adj.get(parent)){
            if(neighbour == parent) continue;
            if(!vis[neighbour]){
                dfs(adj, neighbour, vertex, vis, lowestTime, seqTime, time, isArticulation);
                lowestTime[vertex] = Math.min(lowestTime[vertex], lowestTime[neighbour]);
                if(lowestTime[neighbour] >= seqTime[vertex] && parent != -1) isArticulation[vertex] = true;
                ++children;
            }
            else lowestTime[vertex] = Math.min(lowestTime[vertex], seqTime[neighbour]);
        }
        if(parent == - 1 && children > 1) isArticulation[vertex] = true;
    }

}
