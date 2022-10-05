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