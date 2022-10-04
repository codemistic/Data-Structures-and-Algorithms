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
    int getDecimalValue(ListNode* head) {
        ListNode *curr=head;
        int n=0;
        while(head->next!=NULL)
        {
            n++;
            head=head->next;
        }
        int res=0;
        head=curr;
        while(head!=NULL)
        {
            res=res+((head->val)<<n);
            n--;
            head=head->next;
        }
        return res;
    }
};