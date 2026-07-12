class Solution {
    int[] dp=new int[1001];

    public Solution(){
        Arrays.fill(dp,-1);
    } 
    int helper(int [] cost, int n){
        if(n<=1) return cost[n];
        if(dp[n]!=-1) return dp[n];
        return dp[n]=cost[n]+Math.min(helper(cost,n-1),helper(cost,n-2));
    }
    public int minCostClimbingStairs(int[] cost) {
       int ans=Math.min(helper(cost,cost.length-1),helper(cost,cost.length-2));
       return ans;
    }
}
