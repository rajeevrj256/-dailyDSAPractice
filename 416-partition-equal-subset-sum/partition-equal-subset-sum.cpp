class Solution {
public:
    bool solve(vector<int>& nums,int index,int target,vector<vector<int>>&dp){
        if(target==0) return true;
        if(index>=nums.size() || target<0) return false;

        if(dp[index][target]!=-1) return dp[index][target];
        return dp[index][target]=solve(nums,index+1,target-nums[index],dp) || solve(nums,index+1,target,dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num:nums){
            sum+=num;
        }

        if(sum%2!=0) return false;
        int target=sum/2;
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(nums,0,target,dp);
    }
};