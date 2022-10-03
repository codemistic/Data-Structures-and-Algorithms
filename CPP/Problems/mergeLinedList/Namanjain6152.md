<!-- creating node type own data structure -->
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    if(!head1) return head2;
    if(!head2) return head1;
    Node* dummy= new Node(-1);
    Node* ptr1= head1,*ptr2=head2;
    Node* tail=dummy;
    while(ptr1&&ptr2){
        if(ptr1->data<=ptr2->data){
            tail->next= ptr1;
            tail=ptr1;
            ptr1=ptr1->next;
        }
        else{
            tail->next=ptr2;
            tail=ptr2;
            ptr2=ptr2->next;
        }
    }
    if(ptr1) tail->next=ptr1;
    if(ptr2) tail->next=ptr2;
    return dummy->next;
}  
