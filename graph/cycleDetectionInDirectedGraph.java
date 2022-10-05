import java.util.ArrayList;


// check whether the graph is DAG, directed acyclic(without cycles) graph
public class cycleDetectionInDirectedGraph {
    private boolean checkCycle(int node, ArrayList<ArrayList<Integer>> adj, int[] visited, int dfsVisited[]) {
        visited[node] = 1;
        dfsVisited[node] = 1;
        for (Integer child : adj.get(node)) {
            if (visited[child] == 0) {
                if (checkCycle(child, adj, visited, dfsVisited))
                    return true;
            } else if (dfsVisited[child] == 1)
                return true;
        }
        return false;
    }

    public boolean isCyclic(int N, ArrayList<ArrayList<Integer>> adjlist, int n) {
        int visited[] = new int[N];
        int dfsVisited[] = new int[N];
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                if (checkCycle(i, adjlist, visited, dfsVisited) == true) {
                    return true;
                }
            }
        }
        return false;
    }
}
