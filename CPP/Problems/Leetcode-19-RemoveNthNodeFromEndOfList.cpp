class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        ListNode *slow = head;
        for(int i=1;i<n+1;i++)
        {
            fast = fast->next;
        }
        if(fast == NULL)
        {
            head = head->next;
            return head;
        }
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if(slow->next == NULL)
            head = NULL;
        else
            slow->next = slow->next->next;
        return head;
    }
};