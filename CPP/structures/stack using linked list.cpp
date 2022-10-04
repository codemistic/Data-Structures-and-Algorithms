#include<iostream>
using namespace std;

// Stack implementation using Linked List


// class for _stack
class _stack
{
	// private data---->
	
	
	// node structure
	struct node
	{
		int data;
		node* next;
	};
	node* head = NULL;
	int n = 0;// for size of stack
public:
	// public data---->
	
	
	// push fuction
	void push(int a) {
		// making node 
		node* temp = new node();
		// check whether a stack overflows or not
		if(temp==NULL){cout<<"Stack Overflow\n";return;}
		
		// adding nodes at the beginning of linkked list
		temp->data = a;
		temp->next = head;
		head = temp;
		n++;// increamenting size
	}
	
	// pop function
	void pop() {
		// check stack is empty or not
		if (head == NULL) {cout << "Empty stack\n"; return;}
		// points temp node pointer to the top
		node *temp = head;
		// move head to next node
		head = head->next;
		// delete temp node pointer
		delete(temp);
		n--;// decreamenting size
	}
	
	// top function
	int top() {
		// check stack is empty or not
		if (head == NULL) {cout << "Empty stack"; return -1;}
		// return top node data
		return head->data;
	}
	
	// stack emptly check function
	bool isEmpty() {
		if (head == NULL)return true;
		else return false;
	}
	
	// function for returning the size of stack
	int size() { return n;}
};



int main() {
	
	
	_stack s;
	
	// user/random inputs..
	for (int i = 0; i < 10; ++i) {int a; cin >> a; s.push(a); cout << s.top() << endl;}
	s.pop();
	s.pop();
	cout << s.isEmpty() << endl;
	cout << s.top() << endl;
	s.push(121);
	cout << s.top() << endl;
	return 0;
}
