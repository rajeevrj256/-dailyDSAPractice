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
int ans=INT_MIN;
    int helper(TreeNode*root){
        if(root==NULL) return 0;
        int leftmax=max(0,helper(root->left));
        int rightmax=max(0,helper(root->right));
        ans=max(ans,leftmax+rightmax+root->val);

        return root->val+max(leftmax,rightmax);

    }
    int maxPathSum(TreeNode* root) {
        int x=helper(root);

        return ans;
      
    }
};