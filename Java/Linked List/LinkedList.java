// Author: Vaibhav Pandey
// Date Created: 06/03/2022
// Title: Implementing Linked List data structure in Java from scratch

// Start of LinkedList class
public class LinkedList {

    // Node class representing each element in the list
    static class Node {
        int value;
        Node next;

        // Constructor to initialize the node's value
        public Node(int value) {
            this.value = value;
        }
    }

    // Head of the linked list
    private Node head = null;

    // Add a node at the front of the list
    public void addAtFront(int value) {
        Node node = new Node(value);
        node.next = head;
        head = node;
    }

    // Add a node at the end of the list
    public void addAtEnd(int value) {
        Node node = new Node(value);
        if (head == null) { // If the list is empty
            head = node;
        } else {
            Node current = head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = node;
        }
    }

    // Remove the first node from the list
    public void removeFront() {
        if (head != null) { // Check if the list is not empty
            head = head.next;
        } else {
            System.out.println("List is empty. Nothing to remove.");
        }
    }

    // Print the linked list
    public void print() {
        if (head == null) {
            System.out.println("List is empty.");
            return;
        }

        Node current = head;
        while (current != null) {
            System.out.print(current.value + " -> ");
            current = current.next;
        }
        System.out.println("null");
    }

    // Main function to test the LinkedList class
    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.addAtEnd(5);
        list.addAtEnd(7);
        list.addAtFront(10);
        list.addAtEnd(2);

        System.out.println("Linked List:");
        list.print();

        System.out.println("\nRemoving the first element:");
        list.removeFront();
        list.print();
    }
}
