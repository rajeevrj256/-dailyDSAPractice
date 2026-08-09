class Solution {



 public void backtracking(int []nums,List<Integer> temp,List<List<Integer>> ans,int index,int target){
        if(target==0){
            ans.add(new ArrayList<>(temp));
            return;
        }
        
        if(index>=nums.length || target<0) return;
       
        temp.add(nums[index]);  
        backtracking(nums,temp,ans,index+1,target-nums[index]);

        temp.remove(temp.size()-1);

         while(index+1<nums.length && nums[index]==nums[index+1]){
            index++;
        }
        backtracking(nums,temp,ans,index+1,target);



    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
         List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp=new ArrayList<>();
        Arrays.sort(candidates);
        backtracking(candidates,temp,ans,0,target);
        return ans;
    }
}
