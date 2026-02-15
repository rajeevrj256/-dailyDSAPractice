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
    int height(TreeNode*root,int pos){
        int h=0;
        while(root){
            if(pos){
                root=root->left;
             
            }else{
                root=root->right;
            }
               h++;
        }

        return h;
    }
    int countNodes(TreeNode* root) {
        int left=height(root,1);
        int right=height(root,0);

        if(left==right) return (pow(2,left))-1;

        return 1+countNodes(root->left)+countNodes(root->right);
    }
};