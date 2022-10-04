class Solution {
public:
    void burnTree(TreeNode *root, int time, vector<vector<int>> &ans)
    {
        if(root==NULL)
            return;
        if(time==ans.size())
            ans.push_back({});
        ans[time].push_back(root->val);
        burnTree(root->left, time+1, ans);
        burnTree(root->right, time+1, ans);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        burnTree(root, 0, ans);
        return ans;
    }
};
