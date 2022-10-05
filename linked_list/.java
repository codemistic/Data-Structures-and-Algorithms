// CREATION AND INSERTION

import java.io.*;
public class LinkedList {
	Node head; 

	static class Node {

		int data;
		Node next;

		// Constructor
		Node(int d)
		{
			data = d;
			next = null;
		}
	}
	
	public static LinkedList insert(LinkedList list, int data)
	{
		Node new_node = new Node(data);
		
		if (list.head == null) {
			list.head = new_node;
		}
		else {
	
			Node last = list.head;
			while (last.next != null) {
				last = last.next;
			}

			last.next = new_node;
		}

		return list;
	}

	public static void printList(LinkedList list)
	{
		Node currNode = list.head;
	
		System.out.print("LinkedList: ");
	
		while (currNode != null) {
		
			System.out.print(currNode.data + " ");

			currNode = currNode.next;
		}
	}

	public static void main(String[] args)
	{

		LinkedList list = new LinkedList();


		list = insert(list, 0);
		list = insert(list, 9);
		list = insert(list, 8);
		list = insert(list, 7);
		list = insert(list, 6);
		list = insert(list, 5);
		list = insert(list, 4);
		list = insert(list, 3);

		printList(list);
	}
}
