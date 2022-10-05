
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*

    Intuition
        Use queues to peform bfs and traverse the tree. When you reach depth - 1 ,
        perform the operations mentioned in the question

    Approach
        There are two cases when you reach depth - 1 using bfs.
        Assume curr is the current node at depth - 1

            * curr->left != NULL
            * curr->left == NULL
        The code handles the above two cases.
        There is also one edge case that the code can't handle.
        If the depth is 1 which means we need to add the new_node as the root node.

        So we have to write a seperate code to handle depth = 1 case.
*/
TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        int d = 0;
        if(d == (depth - 1)){
            TreeNode *new_node = new TreeNode(val);
            new_node->left = root;
            root = new_node;
            return root; 
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            d++;
            for(int i=0;i<size;i++){
                TreeNode *curr = q.front();
                q.pop();
                if(!curr)
                    continue;
                if(d == (depth - 1)){
                    TreeNode *new_node = new TreeNode(val);
                    TreeNode *new_node1 = new TreeNode(val);
                    if(curr->left){
                        TreeNode *temp = curr->left;
                        new_node->left = temp;
                        curr->left = new_node;
                    }
                    else{
                        curr->left = new_node;
                    }
                    if(curr->right){
                        TreeNode *temp = curr->right;
                        new_node1->right = temp;
                        curr->right = new_node1;
                    }
                    else{
                        curr->right = new_node1;
                    }
                    
                }
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                
            }
            if(d == (depth-1))
                break;
        }
        return root;
}
=======
/*

623. Add One Row to Tree
Problem Link: https://leetcode.com/problems/add-one-row-to-tree/description/
Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.

Note that the root node is at depth 1.

The adding rule is:

Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.
cur's original left subtree should be the left subtree of the new left subtree root.
cur's original right subtree should be the right subtree of the new right subtree root.
If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original tree, and the original tree is the new root's left subtree.

Input: root = [4,2,6,3,1,5], val = 1, depth = 2
Output: [4,1,1,2,null,null,6,3,1,5]

Input: root = [4,2,null,3,1], val = 1, depth = 3
Output: [4,2,null,1,1,3,null,null,1]

*/

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
    void dfs(TreeNode* root, int val, int depth,int k){
        if(!root)return;
        if(depth==k+1){
            TreeNode *templ=new TreeNode(val);
            TreeNode *l=root->left;
            root->left=templ;
            templ->left=l;
            TreeNode *tempr=new TreeNode(val);
            TreeNode *r=root->right;
            root->right=tempr;
            tempr->right=r;
        }
        dfs(root->left,val,depth,k+1);
        dfs(root->right,val,depth,k+1);
        return;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode *temp=new TreeNode(val);
            temp->left=root;
            return temp;
        }
        dfs(root,val,depth,1);
        return root;
    }
};

