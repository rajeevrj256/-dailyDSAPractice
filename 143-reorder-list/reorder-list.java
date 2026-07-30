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
    public ListNode findMiddle(ListNode head){
        if(head==null) return head;
        ListNode fast=head;
        ListNode slow=head;

        while(fast!=null && fast.next!=null){
               slow=slow.next;
               fast=fast.next.next;
        }


        return slow;
    }

    public ListNode reverse(ListNode head){
        ListNode next=null;
        ListNode prev=null;
        ListNode curr=head;

        while(curr!=null){
            next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
        }

        return prev;
    }
    public void reorderList(ListNode head) {
       
        ListNode middle=findMiddle(head);
        ListNode secondHalf=middle.next;
        middle.next=null;

        ListNode reverseHead=reverse(secondHalf);
        ListNode curr=head;
        ListNode secondNext=null;
        while(curr!=null && reverseHead!=null){
            ListNode temp=curr.next;
            curr.next=reverseHead;
            secondNext=reverseHead.next;
            reverseHead.next=temp;

            reverseHead=secondNext;
            curr=temp;
        }



        

    }
}
