class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> temp;
        while(!q.empty()){
            if(q.front() == NULL){
                ans.push_back(temp);
                temp = {};
                q.pop();
                if(!q.empty()){
                    q.push(NULL);
                }
                continue;
            }
            TreeNode* cn = q.front();
            q.pop();
            temp.push_back(cn->val);
            if(cn->left){
                q.push(cn->left);
            }
            if(cn->right){
                q.push(cn->right);
            }

        }
        return ans;
    }
};