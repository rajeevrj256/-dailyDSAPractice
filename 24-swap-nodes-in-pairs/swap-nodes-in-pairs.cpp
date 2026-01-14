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
    ListNode* swapPairs(ListNode* head) {

        if(head==NULL || head->next==NULL) return head;
       ListNode* i=head;
       ListNode* j=head->next;
       ListNode* prev=NULL;
 head = j;
       while(i!=NULL && j!=NULL){
        ListNode* temp=j->next;

        j->next=i;
        i->next=temp;
        if(prev!=NULL){
            prev->next=j;
        }

        prev=i;
        i=i->next;
        if(i!=NULL && i->next !=NULL){
            j=i->next;
        }else{
            break;
        }
       }

       return head;
    }
};