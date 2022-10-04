# LEETCODE PROBLEM NO. 100 - SAME TREE

# In this problem, we will check if given two trees are same or not. Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

# we will use check if the nodes of given trees are equal or not. if they are, we will further check it's left and right child recursively for the same. if any node is different then we will return false, else True

# ANSWER STARTS FROM HERE = 

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if not p and not q:      #return true if both nodes are Null
            return True
        if not p or not q or p.val != q.val:   #return false if any of the root is Null or value of both roots is not equal
            return False
        
        return self.isSameTree(p.left , q.left) and self.isSameTree(p.right, q.right)

