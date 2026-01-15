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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head==NULL) return head;

     
       
        int n=1;
 
        ListNode* tail=head;
        while(tail->next){
            n++;
            tail=tail->next;
        }
        k=k%n;
        if(k==0) return head;

        tail->next=head;
        int step=n-k;
        ListNode*prev=head;
       for(int i=0;i<step-1;i++){
        prev=prev->next;
       }
       
        ListNode* newHead=prev->next;
        prev->next=NULL;

        return newHead;
    }
};