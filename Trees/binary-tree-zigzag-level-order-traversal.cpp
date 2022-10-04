#include<bits/stdc++.h>

using namespace std;

/**
 * Question Link:- https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(!root) return ans;
        
        queue<TreeNode*> q;
        
        q.push(root);
        bool flag =false;
        
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            
            for(int i=0;i<size;i++){
                
                  TreeNode* node = q.front();
                q.pop();
                
                level.push_back(node->val) ;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
                
                
            }
            
            
            flag = !flag;
            if(flag == false)   
                reverse(level.begin() , level.end()) ;           
        
          
                    ans.push_back(level) ;
                
            
        }
        return ans;
        
    }
};