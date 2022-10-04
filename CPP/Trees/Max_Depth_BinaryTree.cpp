#include <bits/stdc++.h>

using namespace std;

int solve(TreeNode* l, TreeNode* r, int depth)
{
    if(l == NULL && r == NULL)
        return depth - 1;
    
    if(l == NULL)
        return solve(r->left, r->right, depth+1);
    else if(r == NULL)
        return solve(l->left, l->right, depth+1);
    else
    {
        return max(solve(l->left, l->right, depth+1), solve(r->left, r->right, depth+1));
    }
        
}

int maxDepth(TreeNode* root) {
    if(root == NULL)
        return 0;
    
    if(root->left == NULL && root->right == NULL)
        return 1;
    
    return solve(root->left, root->right, 2);
}
