package Java.LinkedList;

import java.util.HashSet;

public class RemoveDuplicatesFromUnsortedList {
    /**
     * Remove Duplicates from Unsorted List
     * For Any Order
     * @param head = linked list with some duplicate element
     * @return list with no duplicate
     */
    public static ListNode deleteDuplicates(ListNode head) {
        if (head == null||head.next ==null){return head;}
        HashSet<Integer> hashSet= new HashSet<>();
        ListNode temp =head;hashSet.add(temp.val);
        ListNode temp2 = head.next;
        while (temp2!=null){
            if (!hashSet.contains(temp2.val)){
                hashSet.add(temp2.val);
                temp =  temp.next;
            }else {
                temp.next = temp.next.next;
            }
            temp2 = temp.next;

        }

        return head;
    }
}

class ListNode{
    int val;
    ListNode next;

    public ListNode(){}

    public ListNode(int val){
        this.val = val;
    }

}
