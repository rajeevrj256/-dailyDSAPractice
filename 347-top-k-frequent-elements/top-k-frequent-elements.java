class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer,Integer>hash=new HashMap<>();

        for(int i=0;i<nums.length;i++){
               hash.put(nums[i],hash.getOrDefault(nums[i],0)+1);
        }

        PriorityQueue<int []>q=new PriorityQueue<>((a,b)-> a[0]-b[0]);

        for(Map.Entry<Integer,Integer>entry:hash.entrySet()){
            q.offer(new int[]{entry.getValue(),entry.getKey()});

            if(q.size()>k) q.poll();
        }

        int[] ans=new int[k];

        for(int i=0;i<k;i++){
            ans[i]=q.poll()[1];
        }

        return ans;
    }
}
