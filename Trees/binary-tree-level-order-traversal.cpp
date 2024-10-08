#include<bits/stdc++.h>

using namespace std;

/**
 * Question Link:- https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
         if(!root) return {};
        
        vector<vector<int>> v;
        
        queue<TreeNode*> q;
         q.push(root);
        
              
        
        while(!q.empty()){
            int siz = q.size();
           
            vector<int> level;
            
            for(int i=0;i<siz;++i){
                 TreeNode* node = q.front();
                q.pop();
                
                if(node){
                    level.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
                
            }
             if(!level.empty()){
                    v.push_back(level);
                }                
         
        } 
        
        
        return v;
    }
};