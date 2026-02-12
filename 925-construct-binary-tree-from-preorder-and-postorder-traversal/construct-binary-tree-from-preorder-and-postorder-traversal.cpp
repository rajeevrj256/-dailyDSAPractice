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
   int prestart=0;
    TreeNode* build(vector<int>&preorder,vector<int>&postorder,int postS,int postE,unordered_map<int,int>&hash){
 if(postS > postE) return NULL;
        TreeNode*root=new TreeNode(preorder[prestart++]);
        
        if(postS==postE || prestart >= preorder.size()) return root;

        int leftRoot=preorder[prestart];
        int index=hash[leftRoot];
        
        int leftSize=index-postS+1;
        root->left=build(preorder,postorder,postS,index,hash);
        root->right=build(preorder,postorder,index+1,postE-1,hash);

        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int,int>hash;
       int i=0;
        for(int post:postorder){
            hash[post]=i++;
        }
        int n=postorder.size();

        return build(preorder,postorder,0,n-1,hash);
    }
};