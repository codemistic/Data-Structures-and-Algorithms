#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left,*right;
};
bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;
    
        if(!root->left && !root->right) // checks if the sum at the root is equal to target sum
            return sum-root->val == 0;
        return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val); // Traverses the tree to find the solution at one of the leaf nodes
}
