class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        while(root)
        {
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = NULL;
           TreeNode* node = root;
            while(node->right)
            {
                node = node->right;
            }
            node->right = temp;
            root = root->right;
        }
    }
};
