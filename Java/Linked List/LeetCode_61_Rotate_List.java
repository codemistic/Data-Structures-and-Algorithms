class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null || head.next == null || k == 0){
            return head;
        }
		
		// calculate the length of the linked list 
        ListNode curr = head;
        int l = 1;
        while(curr.next != null){
            l++;
            curr = curr.next;
        }
		
		//after calculating the length, the current node will be at last node and pointing  to null
		// therefore point the last node(curr) to the head and make a cycle
        curr.next = head;
		
		//in the question k may be a large number and we will be just rotating in the cycle 
		//therefore to avoid the repeatition we will take the modulo value
        k = k % l;
		
		//rotation
		
		//take the remaining length
        l = l - k;
		
		//move the curr node to the last node of the rotated list
        while(l > 0){
            curr = curr.next;
            l--;
        }
		//now the next node will become the head of the new rotated list
        head = curr.next;
		
		//and since curr node is last, the next will become null
        curr.next = null;
        
		//finally just return the head
        return head;
    }
}
