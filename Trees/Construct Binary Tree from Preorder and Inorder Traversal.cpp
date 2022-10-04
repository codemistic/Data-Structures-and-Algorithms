/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int i=0;
    int search(vector<int> inorder, int curr, int s, int e)
    {
        for(int i=s; i<=e; i++)
        {
            if(inorder[i]==curr)
                return i;
        }
        return -1;
    }
    TreeNode *constructTree(vector<int>& preorder, vector<int>& inorder, int s, int e)
    {
        if(s>e)
            return NULL;
        int curr = preorder[i++];
        TreeNode *node = new TreeNode(curr);
        int pos = search(inorder, curr, s, e);
        node->left=constructTree(preorder, inorder, s, pos-1);
        node->right=constructTree(preorder, inorder, pos+1, e);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        return constructTree(preorder, inorder, 0,n-1);
    }
};
