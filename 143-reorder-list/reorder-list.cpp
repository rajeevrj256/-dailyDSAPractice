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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* next=NULL;
        ListNode* curr=head;

        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        return prev;
    }

    ListNode* findMiddle(ListNode*head){
ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }
    void reorderList(ListNode* head) {
        ListNode* midEle=findMiddle(head);

       ListNode * second=reverse(midEle->next);
        midEle->next=NULL;
        ListNode* curr=head;
        ListNode*prev=second;

        while(curr && prev){
            ListNode* firstNext=curr->next;
            ListNode*temp=prev->next;
            curr->next=prev;
            prev->next=firstNext;
            curr=firstNext;
            prev=temp;


        }


    }
};