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
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        if(l1==NULL || l2==NULL) return l1==NULL ? l2 : l1; 
        ListNode *p=new ListNode(-1), *d=p, *c1=l1, *c2=l2;
        while(c1!=NULL and c2!=NULL)
        {
            if(c1->val<=c2->val)
            {
                p->next=c1;
                c1=c1->next;
            }
            else
            {
                p->next=c2;
                c2=c2->next;
            }
            p=p->next;
        }
        p->next = c1!=NULL ? c1 : c2;
        return d->next;
    }
    ListNode *mergeK(vector<ListNode*> lists, int s, int e)
    {
        if(s==e) return lists[s];
        int m=s+((e-s)/2);
        return merge(mergeK(lists,s,m),mergeK(lists,m+1,e));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        int n=lists.size();
        return mergeK(lists,0,n-1);
    }
};