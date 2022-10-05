import java.util.*;

class DFSTraversal {
    private LinkedList<Integer> adj[]; /* adjacency list representation */
    private boolean visited[];

    /* Creation of the graph */
    DFSTraversal(int V) /* 'V' is the number of vertices in the graph */
    {
        adj = new LinkedList[V];
        visited = new boolean[V];

        for (int i = 0; i < V; i++)
            adj[i] = new LinkedList<Integer>();
    }

    /* Adding an edge to the graph */
    void insertEdge(int src, int dest) {
        adj[src].add(dest);
    }

    void DFS(int vertex) {
        visited[vertex] = true; /* Mark the current node as visited */
        System.out.print(vertex + " ");

        // Iterator<Integer> it = adj[vertex].listIterator();
        ListIterator<Integer> ti = adj[vertex].listIterator();
        while (ti.hasNext()) {
            int n = ti.next();
            if (!visited[n])
                DFS(n);
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of vertices");
        int ve = sc.nextInt();
        DFSTraversal graph = new DFSTraversal(ve);
        System.out.println("Enter number of edges");
        int e = sc.nextInt();
        for (int i = 0; i < e; i++) {
            System.out.println("Enter starting vertex of the edge " + i);
            int u = sc.nextInt();
            System.out.println("Enter ending vertex of the edge " + i);
            int v = sc.nextInt();
            graph.insertEdge(u, v);
        }
        System.out.println("Depth First Traversal for the graph is:");
        graph.DFS(0);
    }
}
