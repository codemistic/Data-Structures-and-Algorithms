class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int c=0;
        if(!head) return head;
        ListNode* run=new ListNode(0), *dup=run;
        run->next=head;
        ListNode* k=head;
        while(k!=NULL)
        {
            if(c==n)
            {
                run=run->next;
            }
            else
                c++;
            k=k->next;
        }
        ListNode* temp=run->next;
        run->next=run->next->next;
        
        return dup->next;
    }
};