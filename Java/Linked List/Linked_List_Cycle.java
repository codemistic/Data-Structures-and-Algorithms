/*
  LEETCODE QUESTION : 141. Linked List Cycle

  => There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, 
     pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
    Return true if there is a cycle in the linked list. Otherwise, return false.

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

public class Linked_List_Cycle {
    public boolean hasCycle(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;
        
        //for iteration 
        while(fast!=null && fast.next!=null){
            fast=fast.next.next;   //iterate 2 times
            slow = slow.next;       //iterate 1 time
            
            if(slow== fast)
                return true;
            
        }
        return false;
        
        
    }
    
}
