/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr=head;
        int n=0;
        while(curr){
            curr=curr->next;
            n++;
        }
        vector<ListNode*>ans(k,nullptr);

        int extaEle=n%k;
        int ele=n/k;
        curr=head;
        for(int i=0;i<k;i++){
            ans[i]=curr;
            int size=ele+(extaEle?1:0);
          if (extaEle > 0) extaEle--;

           for(int j=1;j<size;j++){
                curr=curr->next;
            }
            if(curr){
            ListNode* nextptr=curr->next;
            curr->next=NULL;
            curr=nextptr;
            }
        }

        return ans;

    }
};