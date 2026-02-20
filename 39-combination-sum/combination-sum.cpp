class Solution {
public:
    void backtracking(vector<int>&arr,vector<vector<int>>&ans,vector<int>&candidates,int target,int index){
        if(index==candidates.size() || target<0) return;

        if(target==0){
            ans.push_back(arr);
            return;
        }

        arr.push_back(candidates[index]);
       
         backtracking(arr,ans,candidates,target-candidates[index],index);
         arr.pop_back();
          backtracking(arr,ans,candidates,target,index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>arr;
        vector<vector<int>>ans;
        backtracking(arr,ans,candidates,target,0);

        return ans;
    }
};