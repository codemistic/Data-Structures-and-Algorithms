import java.io.*;
import java.util.*;

public class BfsTraversal {
    private int node; /* total number number of nodes in the graph */
    private LinkedList<Integer> adj[]; /* adjacency list */
    private Queue<Integer> que; /* maintaining a queue */

    BfsTraversal(int v) {
        node = v;
        adj = new LinkedList[node];
        for (int i = 0; i < v; i++) {
            adj[i] = new LinkedList<Integer>();
        }
        que = new LinkedList<Integer>();
    }

    void insertEdge(int v, int w) {
        adj[v].add(w);
    }

    void BFS(int n) {
        boolean nodes[] = new boolean[node]; /* initialize boolean array for holding the data */
        int a = 0;
        nodes[n] = true;
        que.add(n); /* root node is added to the top of the queue */
        while (que.size() != 0) {
            n = que.poll(); /* remove the top element of the queue */
            System.out.print(n + " "); /* print the top element of the queue */
            for (int i = 0; i < adj[n].size(); i++) {
                a = adj[n].get(i);
                if (!nodes[a]) /* only insert nodes into queue if they have not been explored already */
                {
                    nodes[a] = true;
                    que.add(a);
                }
            }
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of vertices");
        int ve = sc.nextInt();
        BfsTraversal graph = new BfsTraversal(ve);
        System.out.println("Enter number of edges");
        int e = sc.nextInt();
        for (int i = 0; i < e; i++) {
            System.out.println("Enter starting vertex of the edge " + i);
            int u = sc.nextInt();
            System.out.println("Enter ending vertex of the edge " + i);
            int v = sc.nextInt();
            graph.insertEdge(u, v);
        }
        System.out.println("Breadth First Traversal for the graph is:");
        graph.BFS(0);
    }
}
