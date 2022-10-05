/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
*/
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> q=new PriorityQueue<>((a,b)->a.val-b.val);
        ListNode curr=new ListNode(0);
        ListNode ans=curr;
        
        for(ListNode l:lists){
            while(l!=null){
                q.offer(l);
                l=l.next;
            }
        }
        
        while(!q.isEmpty()){
            curr.next=q.poll();
            curr=curr.next;
            curr.next=null;
        }
        return ans.next;
    }
}
