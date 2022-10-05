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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *curr=head->next;
        ListNode *n=head;
        int cnt=0;
        while(curr!=NULL)
        {
            if(curr->val!=0)
            {
                cnt+=curr->val;
            }
            else
            {
                n->next=curr;
                curr->val=cnt;
                cnt=0;
                n=curr;
            }
            curr=curr->next;
        }
        return head->next;
    }
};