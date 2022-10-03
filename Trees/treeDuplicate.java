import java.util.*;

public class treeDuplicate {
    public static void main(String[] args) {
        node root = new node(2);
        root.left = new node(1);
        root.right = new node(9);
        root.left.left = new node(12);
        root.left.right = new node(2);
        root.right.left = new node(5);
        root.right.right = new node(3);
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        System.out.println(traversal(root, map));
    }

    private static boolean traversal(node root, HashMap<Integer, Integer> map) {
        if (root == null) {
            return false;
        }
        if (map.containsKey(root.data)) {
            return true;
        }
        map.put(root.data, 0);
        return traversal(root.left, map) || traversal(root.right, map);

    }
}

class node {
    int data;
    node left, right;

    node(int value) {
        this.data = value;
    }
}
