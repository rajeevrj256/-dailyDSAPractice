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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        if(!root1 || !root2) return false;
        queue<pair<TreeNode*,TreeNode*>>q;
 

        q.push({root1,root2});  

        while(!q.empty() ){
            int size=q.size();
            auto [node1,node2]=q.front();
            q.pop();
             if(!node1 && !node2) continue;
        if(!node1 || !node2) return false;
        if(node1->val!=node2->val) return false;

        TreeNode* a=node1->left;
         TreeNode* b=node1->right;
          TreeNode* c=node2->left;
 TreeNode* d=node2->right;

 if((a && c && a->val==c->val) || (!a && !c)){
    q.push({a,c});
    q.push({b,d});
 }else{
    q.push({a,d});
    q.push({b,c});
 }
        }

        return true;
    }
};