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
    int ans=0;
    int pathNum=0;
    void helper(TreeNode* root,int sum){
        if(root==NULL) return;
        sum=sum*10+root->val;
        if(!root->left && !root->right){
            ans+=sum;
            return;
        }

        helper(root->left,sum);
        helper(root->right,sum);
    }
    int sumNumbers(TreeNode* root) {
        helper(root,0);

        return ans;
    }
};