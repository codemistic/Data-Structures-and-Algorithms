bool isLoop(Node *head){
   if(head==NULL) return NULL;
   Node *slow=head;
   Node *fast=head;
   while(fast!=NULL && fast->next!=NULL){
       
       slow=slow->next;
       fast=fast->next->next;
       if(slow==fast) return true;
   }
   return false;
   
}
Node *detectLoop(Node *head){
   if(head==NULL) return NULL;
       Node *slow=head;
       Node *fast=head;
       
       while(fast!=NULL && fast->next!=NULL){
           slow=slow->next;
           fast=fast->next->next;
           if(slow==fast) return slow;
       }
       return NULL;
}
Node *removeLoop(Node *head)
{
   if(isLoop(head)==false) return  head;
   Node *fast=detectLoop(head);
          Node *slow=head;
          while(fast!=slow){
           slow=slow->next;
           fast=fast->next;
           
          }
           Node *begin=slow;
           Node *temp=begin;
       
          while(temp->next!=begin){
           temp=temp->next;
          }
          temp->next=NULL;
   return head;
}

