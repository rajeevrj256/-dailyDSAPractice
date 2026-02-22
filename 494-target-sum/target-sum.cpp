class Solution {
public:
    int solve(vector<int>&nums,int target,int index,int sign,int cal){
       
        if(index==nums.size()) return (cal==target)?1:0;

        int plus=solve(nums,target,index+1,0,nums[index]+cal);
        int minus=solve(nums,target,index+1,0,cal-nums[index]);

        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,target,0,0,0);
    }
};