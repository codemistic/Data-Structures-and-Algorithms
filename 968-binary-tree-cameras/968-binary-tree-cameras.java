/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int minCameraCover(TreeNode root) {
        int ans[] = solve(root);
        return Math.min(ans[1],ans[2]);
    }
    
    public int[] solve(TreeNode node)
    {
        if(node == null)
            return new int[]{0,0,9999};
        int l[] = solve(node.left);
        int r[] = solve(node.right);
        
        int ml = Math.min(l[1],l[2]);
        int mr = Math.min(r[1],r[2]);
        
        int d0 = l[1]+r[1];
        int d1 = Math.min(l[2]+mr , r[2]+ml);
        int d2 = 1+Math.min(l[0],ml) + Math.min(r[0],mr);
        
        return new int[]{d0,d1,d2};
    }
}