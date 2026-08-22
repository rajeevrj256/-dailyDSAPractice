class Solution {
    public boolean canFinish(int n, int[][] prerequisites) {

        if(prerequisites.length==0) return true;
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


         while(!q.isEmpty()){
            int top=q.poll();
            courseFree++;
            for(int it:adj.get(top)){
                indegree.set(it,indegree.get(it)-1);

                if(indegree.get(it)==0){
                   
                    q.offer(it);
                }
            }
         }

         return courseFree==n;
    }
}
