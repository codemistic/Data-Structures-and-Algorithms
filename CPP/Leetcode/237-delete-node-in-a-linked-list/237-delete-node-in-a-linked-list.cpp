/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *ptr=node;
        swap(ptr->val,ptr->next->val);
        cout << ptr->val;
        ListNode *p2=ptr->next;
        ptr->next=ptr->next->next;
        delete(p2);
    }
};