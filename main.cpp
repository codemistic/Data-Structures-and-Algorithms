#include <stack>
#include <iostream>
using namespace std;

class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode(int v) {
        val=v;
        next=NULL;
    }
};

ListNode *AddNode() {
    int val;
    cout << "Data Element : " << endl;
    cin >> val;
    ListNode *newNode=new ListNode(val);
    return newNode;
}

bool isPalindrome(ListNode *first) {
    ListNode *head=first;
    stack<int>st;
    while(head) {
        st.push(head->val);
        head=head->next;
    }
    head=first;
    while(head) {
        if(st.top()!=head->val) {
            return false;
        }
        head=head->next;
        st.pop();
    }
    return true;
}

int main() {
    int n;
    cout << "No. of Nodes in Linked List : " << endl;
    cin >> n;
    ListNode *first=AddNode();
    ListNode *previous=first;
    for(int i=0; i<n-1; i=i+1) {
        ListNode *newNode=AddNode();
        previous->next=newNode;
        previous=newNode;
    } 

    cout << isPalindrome(first);
    return 0;
}