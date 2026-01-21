class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode;
        dummy->next = head;
        ListNode*fast = dummy;
        ListNode*slow = dummy;
        for(int i=0;i<n;i++)fast = fast->next;
        while(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};
