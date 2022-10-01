/*
  LEETCODE QUESTION : 206. Reverse Linked List
  => Given the head of a singly linked list, reverse the list, and return the reversed list.
 */

 
 // * Definition for singly-linked list.
public class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

public class Reverse_Linked_List {

    //Submit in leetcode from here :-
    public ListNode reverseList(ListNode head) {
        if (head == null) {
            return head;
        }
        ListNode prev = null;
        ListNode present = head;
        ListNode nextnode = present.next;

        while (present != null) {
            present.next = prev;
            prev = present;
            present = nextnode;
            if (nextnode != null) {
                nextnode = nextnode.next;
            }
        }
        return prev;

    }

}
