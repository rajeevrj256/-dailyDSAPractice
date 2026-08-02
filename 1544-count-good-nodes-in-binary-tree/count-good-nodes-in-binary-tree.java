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
 
     int count=0;
    public void helper(TreeNode root,int maxValue) {
        if(root==null) return;
        if(maxValue<=root.val){
            count++;
            maxValue=root.val;
        }

      helper(root.left,maxValue);
    helper(root.right,maxValue);

       

    }
    public int goodNodes(TreeNode root) {
        if(root==null) return 0;

        helper(root,root.val);

        return count;


    }
}
