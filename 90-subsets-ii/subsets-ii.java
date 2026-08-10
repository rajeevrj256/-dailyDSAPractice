class Solution {
     public void backtracking(int []nums,List<Integer> temp,List<List<Integer>> ans,int index){
        
            ans.add(new ArrayList<>(temp));
           
        for(int i=index;i<nums.length;i++){
            if(i>index && nums[i]==nums[i-1]) continue;

            temp.add(nums[i]);
            backtracking(nums,temp,ans,i+1);
            temp.remove(temp.size() - 1);
        }



    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
         List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp=new ArrayList<>();
       Arrays.sort(nums);
        backtracking(nums,temp,ans,0);
        return ans;
    }
}
