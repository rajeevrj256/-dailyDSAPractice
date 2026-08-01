class ListNode{
    int val;
    int key;
    ListNode prev;
    ListNode next;
    ListNode(){}
    ListNode(int key,int val){
        this.key=key;
        this.val=val;

    }
}
class LRUCache {
    int capacity;
    ListNode head;
    ListNode tail;
      

    HashMap<Integer,ListNode>hash;
    public LRUCache(int capacity) {
        head=new ListNode();
        tail = new ListNode();
        this.capacity=capacity;

        head.next=tail;
        tail.prev=head;
        hash=new HashMap<>();
    }
    
    public void remove(ListNode node){
        node.prev.next=node.next;
        node.next.prev=node.prev;
    }
    public void insert(ListNode node){
        node.next=head.next;
        node.prev=head;

        head.next.prev=node;
        head.next=node;
    }
    public int get(int key) {
        if(!hash.containsKey(key)) return -1;

        ListNode node=hash.get(key);
        remove(node);
        insert(node);

        return node.val;
    }
    
    public void put(int key, int value) {
        if(hash.containsKey(key)){
             ListNode node= hash.get(key);
             node.val=value;
             remove(node);
             insert(node);

            return;
        }

        if(hash.size()== capacity){
            ListNode lru=tail.prev;
            remove(lru);
            hash.remove(lru.key);
        }

        ListNode node=new ListNode(key,value);
        insert(node);
        hash.put(key,node);


    }
}
