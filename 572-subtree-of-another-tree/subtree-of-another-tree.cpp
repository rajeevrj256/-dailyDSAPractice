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
    bool isSame(TreeNode*root,TreeNode*node){
        if(root==NULL || node==NULL){
            return root==node;
        }


        return root->val==node->val && isSame(root->left,node->left) && isSame(root->right,node->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL ) return false;

        return isSame(root,subRoot) || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};