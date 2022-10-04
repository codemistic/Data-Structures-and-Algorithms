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
    private:
    void printer(TreeNode* root){
    if(root==NULL) {return;}
    printer(root->left);
    v.push_back(root->val);
    printer(root->right);
    }
    
public:
    vector<int> v;
    vector<int> inorderTraversal(TreeNode* root) {
        printer(root);
        return v;
    }
};