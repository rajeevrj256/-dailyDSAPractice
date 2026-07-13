class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer,Integer>hash=new HashMap<>();

        for(int i=0;i<nums.length;i++){
               hash.put(nums[i],hash.getOrDefault(nums[i],0)+1);
        }

       List<Integer>[] bucket=new ArrayList[nums.length+1];

        for(Map.Entry<Integer,Integer>entry:hash.entrySet()){
           int freq=entry.getValue();

           if(bucket[freq]==null) bucket[freq]=new ArrayList<>();

           bucket[freq].add(entry.getKey());
        }

        int[] ans=new int[k];
        int index=0;

        for(int i=bucket.length-1;i>=0;i--){
           if(bucket[i]!=null){
            for(int num:bucket[i]){
                ans[index++]=num;


                if(index==k) return ans;
            }
           }
        }

        return ans;
    }
}
