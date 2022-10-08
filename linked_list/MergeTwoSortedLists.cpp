// aproach 1 -
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> ans;
        ListNode *it = list1;
        ListNode *it2 = list2;
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        while(it!=NULL){
            ans.push_back(it->val);
            it = it->next;
        }
        while(it2!=NULL){
            ans.push_back(it2->val);
            it2 = it2->next;
        }
        if(ans.size()==0) return {};
        sort(ans.begin(),ans.end());
        ListNode *node1 = new ListNode();
        ListNode *node2 = node1;
        int i = 0;
        while(i<ans.size()){
            node1 -> val = ans[i];
            ++i;
            if(i>=ans.size()) break;
            node1 -> next = new ListNode();
            node1 = node1 -> next;
        }
        return node2;
    }

//space complexity O(n)

// aproach 2 -  
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * l1 = list1;
        ListNode * l2 = list2;
            if(l1 == NULL) return l2;
            if(l2 == NULL) return l1;
            if(l1->val < l2->val){
                l1->next = mergeTwoLists(l1->next,l2);
                return l1;
            }
            else {
                l2->next = mergeTwoLists(l1,l2->next);
                return l2;
            }
    }
// space complexity : O(1)
