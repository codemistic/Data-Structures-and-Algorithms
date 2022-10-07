// C++ program to find height of tree / Depth of tree
#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
};
int DepthOfTree(node* node)
{
	if (node == NULL)
		return 0;
	else {
		int leftDepth = DepthOfTree(node->left);
		int rightDepth = DepthOfTree(node->right);

		/* use the larger one */
		if (leftDepth > rightDepth)
			return (leftDepth + 1);
		else
			return (rightDepth + 1);
	}
}
node* newNode(int k)
{
	node* Node = new node();
	Node->data = k;
	Node->left = NULL;
	Node->right = NULL;

	return (Node);
}
int main()
{
	node* root = newNode(1);

	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left=newNode(10);
	root->right->right=newNode(20);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->left = newNode(6);


	cout << "Height of tree is " << DepthOfTree(root);
	return 0;
}
