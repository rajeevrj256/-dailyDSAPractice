class Solution {
    public int[] findOrder(int n, int[][] prerequisites) {
        
         List<Integer>indegree=new ArrayList<>();
         List<List<Integer>>adj=new ArrayList<>();

          for (int i = 0; i < n; i++) {
        indegree.add(0);
        adj.add(new ArrayList<>());
    }

        for (int[] prerequisite : prerequisites) {

           int course=prerequisite[0];
           int pre=prerequisite[1];
           adj.get(pre).add(course);


            indegree.set(course,indegree.get(course)+1);
         }

         Queue<Integer>q= new LinkedList<>();
int courseFree=0;
         for(int i=0;i<n;i++){

            if(indegree.get(i)==0) {
                q.offer(i);
               
                }
         }
int count=0;
         List<Integer>ans=new ArrayList<>();
         while(!q.isEmpty()){
            int top=q.poll();
            ans.add(top);
            count++;
            for(int it:adj.get(top)){
                indegree.set(it,indegree.get(it)-1);

                if(indegree.get(it)==0){
                   
                    q.offer(it);
                }
            }
         }
        if(count!=n) return new int[]{};
        int[] result = new int[ans.size()];

        for (int i = 0; i < ans.size(); i++) {
            result[i] = ans.get(i);
        }
        if(result.length==0){
            for(int i=0;i<n;i++){
                result[i]=i+1;
            }
        }
        return result;
    }
}