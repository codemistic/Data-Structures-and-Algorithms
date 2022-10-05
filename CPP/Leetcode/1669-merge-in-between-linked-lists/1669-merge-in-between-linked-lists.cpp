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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int index = 0;
        ListNode * keep = list1;
        ListNode * deleted;
        ListNode * cat;
        while (index != a - 1) {
            keep = keep -> next;
            index ++;
        }
        deleted = keep;

        while (index != b + 1) {
            keep = keep -> next;
            index ++;
        }
        cat = keep;
        deleted -> next = list2;
        while (list2 -> next != nullptr) {
            list2 = list2 -> next;
        }
        list2 -> next = cat;
        return list1;
        
    }
};