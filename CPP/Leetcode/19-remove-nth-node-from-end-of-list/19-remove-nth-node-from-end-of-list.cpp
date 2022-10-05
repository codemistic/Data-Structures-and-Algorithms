/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* ptr=head;  //count the nodes
 int k=0;
 
 while(ptr!=NULL){
     k++;
     ptr=ptr->next;
 }
 
 k=k-n;
 
 //make the pointer to connext the head with dummy node and the ptr to head
 ListNode* dum= new ListNode(-1);
 dum->next=head;
 ptr=dum;
 //run the loop until count not zero
 while(k!=0){
     ptr=ptr->next;
     k--;
 }
 //make the connection 

 ptr->next=ptr->next->next;

 
return dum->next;
    }
};