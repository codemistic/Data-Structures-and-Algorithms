/*
  LEETCODE QUESTION : 876. Middle of the Linked List
  => Given the head of a singly linked list, return the middle node of the linked list.
     If there are two middle nodes, return the second middle node.


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


public class Middle_of_the_Linked_List {

    //Add code from here in Leetcode.
    public ListNode middleNode(ListNode head) {
        
        ListNode fast = head;
        ListNode slow = head;
        
        while(fast!= null && fast.next != null){
            
            slow=slow.next;
            fast= fast.next.next;
            //length=lenght+1;
            
        }
        return slow;
        
       
        
    }
    
}
