Code for merge two sorted list and make a single sorted list


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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        
         // The case where both lists are empty
        if(list1 == null && list2 == null){
            return null;
        // The 2 cases that describe one of the other is empty
        }else if(list1 == null && list2 != null){
            return list2;
        } else if (list1 != null && list2 == null) {
            return list1;
        // The case that describes the beginning of the sorting
        // ie, list1's first value is smaller or equal to list2
        }else if(list1.val <= list2.val) {
            list1.next = mergeTwoLists(list1.next, list2);
           return list1;       
        }else {
            list2.next = mergeTwoLists(list1, list2.next);
           return list2;
        }
    }
}
