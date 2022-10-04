package LinkedList;

 class Node<T> {

    public T data;
    public LinkedList.Node<T> next;

    public Node(T data) {
        this.data = data;
        next = null;
    }
}

public class LengthOfLinkedList {

    public static LinkedList.Node<Integer> createLinkedList() {

        LinkedList.Node<Integer> n1 = new LinkedList.Node<>(10);
        LinkedList.Node<Integer> n2 = new LinkedList.Node<>(20);
        LinkedList.Node<Integer> n3 = new LinkedList.Node<>(30);
        LinkedList.Node<Integer> n4 = new LinkedList.Node<>(40);
        LinkedList.Node<Integer> n5 = new LinkedList.Node<>(50);

        n1.next = n2;
        n2.next = n3;
        n3.next = n4;
        n4.next = n5;
        return n1;

    }

    public static int length1(LinkedList.Node<Integer> head) {

        int count = 0;
        LinkedList.Node<Integer> temp = head;
        while (temp != null) {
            count++;
            temp = temp.next;
        }
        return count;

    }

    public static void main(String[] args) {

        LinkedList.Node<Integer> head = createLinkedList();
        int ans = length1(head);
        System.out.println(ans);

    }

}