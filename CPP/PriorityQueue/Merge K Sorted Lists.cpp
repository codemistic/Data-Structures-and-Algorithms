/*
This is a frequently asked quetion in coding interviews by many companies.
You are given a vector of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.
Example1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example2:
Input: lists = [[]]
Output: []
*/

#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* mergeKLists(vector<ListNode*>& lists) {
    //1. Create a min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    //2. push all of the elements in the min heap.
    for(auto list: lists){
        while(list != NULL){
            minHeap.push(list->val);
            list = list->next;
        }
    }
    //3. Create a node to store the values.
    ListNode* dummy = new ListNode(-1);
    ListNode* head = dummy;
    //4. iterate through the min heap and store each value into the linked list
    while(!minHeap.empty()){
        head->next = new ListNode(minHeap.top());
        minHeap.pop();
        head = head->next;
    }
    return dummy->next;
}