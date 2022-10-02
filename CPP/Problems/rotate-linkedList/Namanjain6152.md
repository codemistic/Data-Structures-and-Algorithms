<!-- reverse linked list logic iterative -->
ListNode* reverse(ListNode* head){
        if(!head||!head->next) return head;
        ListNode* next=NULL, *curr=head, *prev= NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
<!--rotate a linked list by k in right      -->
 ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next) return head;
        ListNode* length= head;
        int len=0;
        while(length){
            length=length->next;
            len++;
        }
       
        
        ListNode* fast= head,*slow=head;
        int val= k%len;
        
        while(fast&&val>0){
            fast=fast->next;
            val--;
        }
        if(fast==NULL){
            return reverse(head);
        }
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        fast= slow->next;
        slow->next=NULL;
        slow=head;
       ListNode* first= reverse(slow);
      ListNode* second= reverse(fast);
        ListNode* temp=first;
        while(temp->next){
            temp=temp->next;
        }
        temp->next= second;
        return reverse(first);
    }
