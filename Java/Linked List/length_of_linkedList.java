package LinkedList;

 class node<T> {

    public T data;
    public node<T> next;

    public node(T data) {
        this.data = data;
        next = null;
    }
}

public class length_of_linkedList {

    public static node<Integer> createLinkedList() {

        node<Integer> n1 = new node<>(10);
        node<Integer> n2 = new node<>(20);
        node<Integer> n3 = new node<>(30);
        node<Integer> n4 = new node<>(40);
        node<Integer> n5 = new node<>(50);

        n1.next = n2;
        n2.next = n3;
        n3.next = n4;
        n4.next = n5;
        return n1;

    }

    public static int length1(node<Integer> head) {

        int count = 0;
        node<Integer> temp = head;
        while (temp != null) {
            count++;
            temp = temp.next;
        }
        return count;

    }

    public static void main(String[] args) {

        node<Integer> head = createLinkedList();
        int ans = length1(head);
        System.out.println(ans);

    }

}