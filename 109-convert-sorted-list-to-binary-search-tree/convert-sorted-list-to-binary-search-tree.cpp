class Solution {
public:
    ListNode* curr;   // global pointer

    int getSize(ListNode* head){
        int count = 0;
        while(head){
            count++;
            head = head->next;
        }
        return count;
    }

    TreeNode* buildBST(int n){
        if(n <= 0) return NULL;

        // build left subtree
        TreeNode* left = buildBST(n/2);

        // current node becomes root
        TreeNode* root = new TreeNode(curr->val);
        curr = curr->next;

        // build right subtree
        root->left = left;
        root->right = buildBST(n - n/2 - 1);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        curr = head;
        int n = getSize(head);
        return buildBST(n);
    }
};
