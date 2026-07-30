/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int lenNode=0;
        ListNode curr=head;
        while(curr!=null){
            lenNode=lenNode+1;
            curr=curr.next;
        }

        if(lenNode==n) return head.next;
        int k=lenNode-n-1;
        curr=head;
        while(k>0){
           curr=curr.next;
           k--;
        }

        curr.next=curr.next.next;

        return head;
    }
}
