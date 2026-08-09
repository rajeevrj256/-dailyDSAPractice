class Solution {


     public void backtracking(int []nums,List<Integer> temp,List<List<Integer>> ans,int index,int target){
        if(target==0){
            ans.add(new ArrayList<>(temp));
            return;
        }
        
        if(index>=nums.length || target<0) return;
       
        temp.add(nums[index]);  
        backtracking(nums,temp,ans,index,target-nums[index]);

        temp.remove(temp.size()-1);
        backtracking(nums,temp,ans,index+1,target);



    }


    public List<List<Integer>> combinationSum(int[] nums, int target) {
         List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp=new ArrayList<>();
        
        backtracking(nums,temp,ans,0,target);
        return ans;
    }
}
