//question = https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int n=0;
        ListNode* cur = head;;
        while(cur!=NULL){
            n++;
            cur = cur->next;
        }
        int sum = 0;
        while(head!=NULL){
            
            int data = head->val;
            sum += (data*pow(2,n-1));
            head= head->next;
            // std::cout << sum <<endl;
            n--;
        }
        return sum;
    }
};