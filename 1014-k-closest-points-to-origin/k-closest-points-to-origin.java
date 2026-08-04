
class Node{
    int value;
    int[] p;

    Node(int value,int[] p){
        this.value=value;
        this.p=p;
    }
};

class Solution {
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<Node>pq=new PriorityQueue<>((a,b)->Integer.compare(b.value,a.value));
        int i=0;
        int n=points.length;
        while(i<n){
          int[] point=points[i];
          int x2=0;
          int y2=0;
          int x1=point[0];
          int y1=point[1];

          int distance = x1 * x1 + y1 * y1;
          Node node=new Node(distance,point);
          pq.offer(node);

          while(pq.size()>k){
            pq.poll();
          }
          i++;
        }

      
        int ans[][]= new int[k][2];
        int idx=0;

        while(!pq.isEmpty() && idx<k){
            ans[idx]=pq.peek().p;
            pq.poll();
            idx++;
        }
        return ans;

    }
}
