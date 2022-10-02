// https://leetcode.com/problems/palindrome-linked-list/
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head == null || (head != null && head.next == null)) return true;
        
        ListNode slow = head, fast = head.next, prevFast = head;
        
        while(fast != null && fast.next != null){
            slow = slow.next;
            prevFast = fast.next;
            fast = fast.next.next;
        }
        
        ListNode prev = null, curr = slow.next, next = null;
        slow.next = (fast == null) ? prevFast : fast;
        while(curr != null){
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        
        ListNode temp = head;
        curr = slow.next;
        while(curr != null){
            if(temp.val != curr.val) return false;
            temp = temp.next;
            curr = curr.next;
        }
        
        return true;
    }
}
