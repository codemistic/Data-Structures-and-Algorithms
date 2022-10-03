// https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    public ListNode reverseKGroup(ListNode head, int k) {
        if (k == 1) return head;

        ListNode slow = head, fast = head, newHead = head;
        ListNode prev = null, next = head;
        int count = 0;
        boolean isStart = true;

        while (fast != null) {
            count++;

            if (count != k) fast = fast.next;
            else {
                if (!isStart) {
                    next = slow.next;
                    slow.next = fast;
                    slow = next;
                } else {
                    isStart = false;
                    newHead = fast;
                }

                prev = fast.next;
                ListNode tempFast = fast.next, tempSlow = slow;
                while (count > 0) {
                    count--;
                    next = slow.next;
                    slow.next = prev;
                    prev = slow;
                    slow = next;
                }
                slow = tempSlow;
                fast = tempFast;
            }
        }

        return newHead;
    }
}
