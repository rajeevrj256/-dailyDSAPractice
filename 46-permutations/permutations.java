class Solution {

     public void backtracking(int []nums,List<Integer> temp,List<List<Integer>> ans,boolean[] used){
        if(temp.size()==nums.length){
            ans.add(new ArrayList<>(temp));
            return;
        }
       
        for(int i=0;i<nums.length;i++){
           if(used[i]) continue;

            temp.add(nums[i]);
            used[i]=true;
            backtracking(nums,temp,ans,used);

            temp.remove(temp.size()-1);
            used[i]=false;
        }



    }

    public List<List<Integer>> permute(int[] nums) {
          List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp=new ArrayList<>();
 boolean[] used = new boolean[nums.length];
         backtracking(nums,temp,ans,used);
        return ans;
    }
}
