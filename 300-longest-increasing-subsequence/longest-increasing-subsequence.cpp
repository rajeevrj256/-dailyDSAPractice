class Solution {
public:
    int solve(vector<int>&nums,int index,int prevIndex,vector<vector<int>>&dp){
        if(index>=nums.size()) return 0;

        if(dp[index][prevIndex+1]!=-1) return dp[index][prevIndex+1];
        int take=0;
        if(prevIndex==-1 || nums[prevIndex]<nums[index]){
           take=1+solve(nums,index+1,index,dp);
        }

        int skip=solve(nums,index+1,prevIndex,dp);

        return dp[index][prevIndex+1]=max(skip,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(ans.size()==0 || ans.back()<nums[i]){
                ans.push_back(nums[i]);
            }else{
                int lower_index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[lower_index]=nums[i];
            }
        }
         return ans.size();
    }
};