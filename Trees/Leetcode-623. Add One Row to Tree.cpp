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
    
    // getting all parent nodes for which we want to append nodes 
    void getBfs(TreeNode* root, int depth , vector<TreeNode*>&v){
        if(depth==1 && root!=NULL){
            v.push_back(root);
            return;
        }
        if(root==NULL)return;
        
        getBfs(root->left , depth-1 , v);
        getBfs(root->right , depth-1 , v);
        
        return;
    }
    
    //creating nodes
    TreeNode* createNode(int val){
        TreeNode *temp=new TreeNode;
        temp->val = val;
        return temp;
    }
    
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        //if depth ==1
        if(depth==1){
            TreeNode* temp = createNode(val);
            temp ->left = root;
            return temp;
        }
        
        
        vector<TreeNode*>v;
        getBfs(root , depth-1 , v);
        int s = v.size();
        
        for(int i=0; i<s; i++){
            TreeNode* temp1 = createNode(val);
            TreeNode* temp2 = createNode(val);
            TreeNode *t = v[i];
            if(t->left && t->right){
                temp1->left=t->left;
                temp2->right=t->right;
                t->left = temp1;
                t->right = temp2;
            }
            else if(t->left && t->right==NULL){
                temp1->left=t->left;
                t->left = temp1;
                t->right = temp2;
            }
            else if(t->left==NULL && t->right){
                temp2->right=t->right;
                t->left = temp1;
                t->right = temp2;
            }
            else{
                t->left = temp1;
                t->right = temp2;
            }
        }
        
        
        return root;
        
        
    }
};