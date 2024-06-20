//Program to find Postorder Binary Tree
#include<bits/stdc++.h>
using namespace std;
struct Node {
	int key;
	struct Node*left;
	struct Node*right;
	Node(int K)
	{
		key=K;
		left=right=NULL;
	}
};
void inorder(Node*root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		inorder(root->right);
		cout<<root->key<<" ";

	}
}
int main()
{
	Node*root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	inorder(root);
}

//Output Generated
//20 40 50 30 10 