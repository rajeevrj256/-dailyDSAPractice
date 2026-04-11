class Solution {
    public int findMiniWindow(List<Integer> index){
        int i=0;
        int j=0;
        int n=index.size();
        int minDist=Integer.MAX_VALUE;
        while(j<n){
            if(j-i+1<3)j++;
            else if(j-i+1==3){
                int dist=2*(index.get(j)-index.get(i));
                minDist=Math.min(minDist,dist);
                i++;
                j++;
            }
        }

        return minDist;
    }
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