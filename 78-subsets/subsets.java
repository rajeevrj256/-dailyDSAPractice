class Solution {
    public void backtracking(int []nums,List<Integer> temp,List<List<Integer>> ans,int index){
        if(index==nums.length){
            ans.add(new ArrayList<>(temp));
            return;
        }

       
        temp.add(nums[index]);  
        backtracking(nums,temp,ans,index+1);

        temp.remove(temp.size()-1);
        backtracking(nums,temp,ans,index+1);



    }
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp=new ArrayList<>();
        
        backtracking(nums,temp,ans,0);
        return ans;
    }
}
