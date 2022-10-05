class Solution {
public:
    vector<int>num;
    int kthSmallest(TreeNode* root, int k) {
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
        sort(num.begin(), num.end());
        return num[k-1];
    }
};