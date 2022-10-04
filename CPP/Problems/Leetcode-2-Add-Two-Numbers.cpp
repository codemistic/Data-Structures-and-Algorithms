// https://leetcode.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* ll = dummy;
        int carry = 0;
        int sum = 0;
        while(l1 and l2){
            sum = l1->val + l2->val + carry;
            ll->next = new ListNode(sum%10);
            ll = ll->next;
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            sum = l1->val + carry;
            ll->next = new ListNode(sum%10);
            ll = ll->next;
            carry = sum/10;
            l1 = l1->next;
            
        }
        while(l2){
            sum = l2->val + carry;
            ll->next = new ListNode(sum%10);
            ll = ll->next;
            carry = sum/10;
            l2 = l2->next;
        }
        if(carry != 0){
            ll->next = new ListNode(carry);
            ll = ll->next;
        }
        return dummy->next;
    }
};
