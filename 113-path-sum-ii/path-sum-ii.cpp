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
    void helper(TreeNode* root,vector<vector<int>>&ans,vector<int>&res,int targetSum,int sum){
        if(root==NULL) return ; 

        sum+=root->val;
        res.push_back(root->val);
        if(!root->left && !root->right){
            if(sum==targetSum){
                ans.push_back(res);
               
            }
            res.pop_back();
            return;
        }

        helper(root->left,ans,res,targetSum,sum);
        
        
        helper(root->right,ans,res,targetSum,sum);
 res.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>res;
        helper(root,ans,res,targetSum,0);
        return ans;
    }
};