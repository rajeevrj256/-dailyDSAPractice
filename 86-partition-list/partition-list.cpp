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
    ListNode* partition(ListNode* head, int x) {

       ListNode*beforeDummy=new ListNode(0);
    
        ListNode*afterDummy=new ListNode(0);

        ListNode*before=beforeDummy;
        ListNode* after=afterDummy;

      
        ListNode* curr=head;

        while(curr){
            if(curr->val<x){
                before->next=curr;
                before=before->next;
            }else{
                after->next=curr;
                after=after->next;
            }

            curr=curr->next;
        }
        after->next=NULL;
        before->next=afterDummy->next;

        return beforeDummy->next;


    }
};