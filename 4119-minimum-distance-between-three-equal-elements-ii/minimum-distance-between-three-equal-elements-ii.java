class Solution {
    
    public int minimumDistance(int[] nums) {
        Map<Integer,List<Integer>>hash=new HashMap<>();

        for(int i=0;i<nums.length;i++){
            hash.computeIfAbsent(nums[i],k->new ArrayList<>()).add(i);
        }
       
        int mini = Integer.MAX_VALUE;
        for(List<Integer>arr:hash.values()){
            if(arr.size()>=3){
               for(int i=0;i+2<arr.size();i++){
               int dist=2*(arr.get(i+2)-arr.get(i));
               mini=Math.min(mini,dist);
               }
            }
        }

        return mini==Integer.MAX_VALUE?-1:mini;
    }
}