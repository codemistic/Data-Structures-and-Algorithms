import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

// CORE: if children is already visited and
//  is not the parent of the node then there isa cycle
public class cycledetectionInUndirectedGraph {
    private boolean isCycle(int V, ArrayList<ArrayList<Integer>> adj) {
        boolean[] visited = new boolean[V + 1];
        Arrays.fill(visited, false);
        for (int i = 1; i <= V; i++) {
            if (!visited[i]) {
                if (checkForCycle(adj, i, visited))
                    return true;
            }
        }
        return false;
    }

    static boolean checkForCycle(ArrayList<ArrayList<Integer>> adj, int s, boolean visited[]) {
        Queue<Node> q = new LinkedList<>(); // bfs queue
        q.add(new Node(s, -1)); // add source node parent of start Node is -1 <-- 0
        visited[s] = true;
        while (!q.isEmpty()) {
            int node = q.peek().self;
            int parent = q.peek().Parent;
            q.remove();
            for (Integer child : adj.get(node)) {
                if (!visited[child]) {
                    q.add(new Node(child, node));
                    visited[child] = true;
                } else if (child != parent) { // child is visited and is not parent, then cycle
                    return true;
                }
            }
        }
        return false;

    }

    // driver code
    public static void main(String[] args) {
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        adj.add(new ArrayList<>(Arrays.asList(1, 2)));
        adj.add(new ArrayList<>(Arrays.asList(2, 3)));
        adj.add(new ArrayList<>(Arrays.asList(3, 4)));
        // adj.add(new ArrayList<>(Arrays.asList(4, 5)));
        cycledetectionInUndirectedGraph obj = new cycledetectionInUndirectedGraph();
        System.out.println(obj.isCycle(4, adj));
    }
}

class Node {
    int self;
    int Parent;

    public Node(int self, int Parent) {
        this.self = self;
        this.Parent = Parent;
    }
}

class cycleDetectionUsingDSU{
    
}