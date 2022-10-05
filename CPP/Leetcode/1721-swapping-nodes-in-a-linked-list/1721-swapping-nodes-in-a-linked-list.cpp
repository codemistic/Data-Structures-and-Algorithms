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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *curr=head;
        ListNode *node=head;
        ListNode *hehe=head;
        int n=0;
        while(hehe->next!=NULL)
        {
            hehe=hehe->next;
            n++;
        }
        int i=1;
        while(i!=k)
        {
            curr=curr->next;
            i++;
        }
        i=0;
        while(i!=(n-k+1))
        {
            node=node->next;
            i++;
        }
        int temp=curr->val;
        curr->val=node->val;
        node->val=temp;
        return head;
        
        
    }
};



        