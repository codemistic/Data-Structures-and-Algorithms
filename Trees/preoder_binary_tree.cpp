//Program to find Preorder Binary Tree
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
		cout<<root->key<<" ";
		inorder(root->left);
		inorder(root->right);

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

//Output Generated:
//10 20 30 40 50 