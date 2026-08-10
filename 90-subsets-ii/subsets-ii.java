class Solution {
     public void backtracking(int []nums,List<Integer> temp,List<List<Integer>> ans,int index){
        if(index==nums.length){
            ans.add(new ArrayList<>(temp));
            return;
        }

       
        temp.add(nums[index]);  
        backtracking(nums,temp,ans,index+1);

        temp.remove(temp.size()-1);

        while(index+1<nums.length && nums[index]==nums[index+1]) index++;
        backtracking(nums,temp,ans,index+1);



    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
         List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp=new ArrayList<>();
       Arrays.sort(nums);
        backtracking(nums,temp,ans,0);
        return ans;
    }
}
