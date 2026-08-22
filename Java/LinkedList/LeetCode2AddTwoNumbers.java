/*https://leetcode.com/problems/add-two-numbers/*/ 


   /*
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

 /* Question:
  * There given a two linked lists and we need to add the value of each node of two linked lists and stored in a new linkedlist such that the new linkedlist should have only a single digit stored in its each node.
  example:
       l1=[2,4,3]  
       l2=[5,6,4] 
       ans=[7,0,8]
  APPROACH:
     1) create a new linkedlist which contains the sum.
     2) create a dummy node to traverse the answer list and add elements into it.
     3)take a carry variable to store the carry that was obtained after adding the sum and need to be added to the next nodes sum(in the above example:4+6=10, carry contains 1 and 0 is added to the answer list).
     4)traverse both the given lists and obtain the sum of their each nodes values along with carry.
     5)store the sum in the new linked list.

  */

  public class Solution{
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        //The answer node
       ListNode head = new ListNode(); 
       //A temporary node to traverse and add the nodes into the answer list. 
        ListNode dummy=head; 
        //A carry variable           
        int carry=0;
        while(l1!=null || l2!=null || carry!=0){
            //store each nodes value into sum variable 
            int sum=0;   
            if(l1!=null){
                sum+=l1.val;  
                l1=l1.next;  
            }
            if(l2!=null){ 
                sum+=l2.val; 
                l2=l2.next;
            }
            sum+=carry;  
            carry=sum/10;
            ListNode currNode = new ListNode(sum%10);  
            dummy.next = currNode;   
            dummy = currNode;
        }
       
        return head.next; 
    }
} 

