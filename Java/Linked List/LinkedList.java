//Author: Vaibhav Pandey
//Date Created: 06/03/2022
//Title: Implementing Linked List data structure in Java from scratch


//Start of main LinkedList class
public class LinkedList{

    //Node class for storing current node's value and the address to the next node
    static class Node{
        Node next;
        int value;

        //Constructor that initializes node's value
        public Node(int value){
            this.value = value;
        }
    }

    //Initializing the first node to null
    Node first = null;

    //Function for adding elements at the front of the list
    public void addAtFront(Node node){
        //Assign the next node's address to first and store the current node's address in first
        node.next = first;
        first = node;
    }

    //Function for adding elements at the end of the list
    public void addAtEnd(Node node){
        //If the list is already empty, just assign the first address to the current node
        if(first == null){
            first = node;
        }
        //If the list is not empty, traverse the list from the first element to the last element and add the current node at last
        else{
            Node ptr = first;
            while(ptr.next != null){
                ptr = ptr.next;
            }
            ptr.next = node;
        }
    }

    //Function for removing the first element of the list
    public void removeFront(){
        //To remove the first element, just set the next element to first
        first = first.next;
    }


    //Function to print the list
    public void print(){
        //For printing just traverse the list from first to last
        Node ptr = first.next;
        System.out.print(first.value);
        while(ptr != null){
            System.out.print(" -> " + ptr.value);
            ptr = ptr.next;
        }
        System.out.println(" -> null");
        //The last element of the list points to null
    }

    //Main function to run the LinkedList class
    public static void main(String[] args){
        LinkedList list = new LinkedList();
        list.addAtEnd(new Node(5));
        list.addAtEnd(new Node(7));
        list.addAtFront(new Node(10));
        list.addAtEnd(new Node(2));
        list.print();
    }

}