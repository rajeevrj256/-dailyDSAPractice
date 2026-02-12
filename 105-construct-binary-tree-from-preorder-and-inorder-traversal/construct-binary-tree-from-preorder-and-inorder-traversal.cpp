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
    TreeNode*build(vector<int>&preorder,int preOrderStart,int preOrderEnd,vector<int>&inorder,int inOrderStart,int inOrderEnd,unordered_map<int,int>&hash){
        if(preOrderStart>preOrderEnd ||inOrderStart>inOrderEnd) return NULL;
        TreeNode* root=new TreeNode(preorder[preOrderStart]);
        int rootIndex=preorder[preOrderStart];
        int index=hash[rootIndex];

        int length=index-inOrderStart;

        root->left=build(preorder,preOrderStart+1,preOrderStart+length,inorder,inOrderStart,inOrderStart+length,hash );
        root->right=build(preorder,preOrderStart+length+1,preOrderEnd,inorder,inOrderStart+length+1,inOrderEnd,hash );

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>hash;
        int i=0;
        for(int in:inorder){
            hash[in]=i;
            i++;
        }
        int n=preorder.size();
        return build(preorder,0,n-1,inorder,0,n-1,hash);
    }
};