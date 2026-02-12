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
int preStart=0;
    TreeNode*build(vector<int>&preorder,vector<int>&inorder,int inOrderStart,int inOrderEnd,unordered_map<int,int>&hash){
        if(inOrderStart>inOrderEnd) return NULL;
        int rootval=preorder[preStart++];
        TreeNode* root=new TreeNode(rootval);
        
        int index=hash[rootval];


        root->left=build(preorder,inorder,inOrderStart,index-1,hash );
        root->right=build(preorder,inorder,index+1,inOrderEnd,hash );

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
        return build(preorder,inorder,0,n-1,hash);
    }
};