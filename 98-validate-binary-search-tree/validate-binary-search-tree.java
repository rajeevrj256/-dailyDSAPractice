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
    public boolean helper(TreeNode root,Long maxValue,Long minValue){
        if(root==null) return true;

        if(root.val<=minValue || root.val>=maxValue) return false;


        return helper(root.left,(long)root.val,minValue) && helper(root.right,maxValue,(long)root.val);
    }
    public boolean isValidBST(TreeNode root) {

        if(root==null) return true;

        return helper(root,Long.MAX_VALUE,Long.MIN_VALUE);
        
    }
}
