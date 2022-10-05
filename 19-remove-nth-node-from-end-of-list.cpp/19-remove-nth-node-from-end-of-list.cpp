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
        int cnt=0;
        ListNode* curr=head;
        while(curr){
            curr=curr->next;
            cnt++;
        }curr=head;
        if(n==1 && cnt==1)
            return NULL;
        if(cnt-n==0)
            return head->next;
        for(int i=1;i<cnt-n;i++){
            curr=curr->next;
        }
        if(curr->next==NULL)
            return head;
        if(curr->next->next==NULL)
            curr->next=NULL;
        else
            curr->next=curr->next->next;
        return  head;
    }
};