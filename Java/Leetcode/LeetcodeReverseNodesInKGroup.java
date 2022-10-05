class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        
        if(k<=1 || head == null) return head;
        
        ListNode current = head;
        ListNode prev = null;
        ListNode temp = head;
        int count = 0;
        while(temp != null){
            count++;
            temp = temp.next;
        }
        int run = count/k;
        
        while(true){
            if(run==0) break;
            ListNode last = prev;
            ListNode newEnd = current;
            
            ListNode next = current.next;
            
            for(int i=0; current != null && i<k;i++){
                current.next = prev;
                prev = current;
                current = next;
                if(next != null){
                    next = next.next;
                }
            }
            
            if(last != null){
                last.next = prev;
            }
            else{
                head = prev;
            }
            newEnd.next = current;
            
            if(current == null ){
                break;
            }
            prev = newEnd;
            run--;
            
        }
        return head;
    }
}