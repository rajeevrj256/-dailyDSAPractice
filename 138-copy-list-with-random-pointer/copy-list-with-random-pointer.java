/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        Node copiedHead=new Node(0);
        Node newHead=copiedHead;
        HashMap<Node,Node>hash=new HashMap<>();
        Node curr=head;
        
        while(curr!=null){
            Node temp=new Node(curr.val);
            newHead.next=temp;
            hash.put(curr, temp);
            newHead=newHead.next;
            
            curr=curr.next;
        }

        curr=head;
        newHead=copiedHead.next;
        while(newHead!=null && curr!=null){
            Node random=curr.random;
            if(random==null) newHead.random=null;
            else{
                Node corrNode=hash.get(random);
                newHead.random=corrNode;
            }

            newHead=newHead.next;
            curr=curr.next;
        }

        return copiedHead.next;
    }
}
