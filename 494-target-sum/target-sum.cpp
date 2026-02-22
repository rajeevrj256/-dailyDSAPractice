class Solution {
public:
    int solve(vector<int>&nums,int target,int index,int cal,vector<vector<int>>&dp,int offset){
        
        if(index==nums.size()) return (cal==target)?1:0;
        if(dp[index][cal+offset]!=-1) return dp[index][cal+offset];
        int plus=solve(nums,target,index+1,nums[index]+cal,dp,offset);
        int minus=solve(nums,target,index+1,cal-nums[index],dp,offset);

        return dp[index][cal+offset]=plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totalSum=0;
        for(int num:nums){
            totalSum+=num;
        }
        vector<vector<int>>dp(n,vector<int>(2*totalSum+1,-1));
        return solve(nums,target,0,0,dp,totalSum);
    }
};