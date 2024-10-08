class Solution {
public:
    vector<int>num;
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        queue<TreeNode*>q;
        q.push(root);
    while(!q.empty()){
        TreeNode*curr = q.front();
        num.push_back(curr->val);
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
        q.pop();
        }
    return num.size();
    }
};