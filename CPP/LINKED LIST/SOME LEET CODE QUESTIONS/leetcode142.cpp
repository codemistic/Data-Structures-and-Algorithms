//question = https://leetcode.com/problems/linked-list-cycle-ii/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* cur1 = head;
        ListNode *cur2 = head;
        ListNode *entry = head;
        if(head == NULL || head->next==NULL) // Condition 1
        {
            return NULL;
        }
        while(cur2->next!=NULL && cur2->next->next!=NULL){
            cur1 = cur1-> next;
            cur2 = cur2 ->next ->next;
            if(cur1 == cur2){
                while(cur1 != entry){   //found the entry location
                    cur1 = cur1 ->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;

}
    };
