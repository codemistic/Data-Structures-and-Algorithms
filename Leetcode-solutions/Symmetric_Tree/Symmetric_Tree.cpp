

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
        if(!root)
            return true;

        return areMirror(root->left, root->right);
        
    }
    
    bool areMirror(TreeNode* t1, TreeNode* t2){
        if(!t1 || !t2)
            return (t1 == t2);

        if(t1->val != t2->val) 
            return false;

        return ( areMirror(t1->left, t2->right) && areMirror(t1->right, t2->left) );
    
    }
};