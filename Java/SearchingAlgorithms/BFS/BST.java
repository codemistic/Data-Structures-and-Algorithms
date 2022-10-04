import java.util.LinkedList;
import java.util.ArrayList;
public class BST {
    Node root;

    BST(){
        root = null;
    }

    class Node{
        int value;
        Node left;
        Node right;

        Node(int value){
            this.value = value;
        }
    }

    // insert
    public void insert(int value){
        if(root == null){
            Node n = new Node(value);
            root = n;
        }
        else{
            Node tmp = root;
            while(true){
                if(value >= tmp.value){
                    if(tmp.right == null){
                        tmp.right = new Node(value);
                        break;
                    }
                    else{
                        tmp = tmp.right;
                    }
                }
                else{
                    if(tmp.left == null){
                        tmp.left = new Node(value);
                        break;
                    }
                    else{
                        tmp = tmp.left;
                    }
                }
            }
            tmp = null;
        }
    }

    // find/lookup
    public boolean contains(int value){
        if(root == null){
            return false;
        }
        else{
            Node tmp = root;
            while(tmp != null){
                if(tmp.value == value){
                    return true;
                }
                if(value >= tmp.value){
                    tmp = tmp.right;
                }
                else{
                    tmp = tmp.left;
                }
            }
            return false;
        }
    }

    public ArrayList<Integer> breadthFirstSearch(){
        ArrayList<Integer> output = new ArrayList<Integer>();
        LinkedList<Node> queue = new LinkedList<Node>();
        queue.addLast(this.root);
        while(queue.size() > 0){
            Node current = queue.removeFirst();
            output.add(current.value);
            if(current.left != null) queue.addLast(current.left);
            if(current.right != null) queue.addLast(current.right);
        }
        return output;
    }

}