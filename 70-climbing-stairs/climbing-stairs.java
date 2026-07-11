class Solution {
    int[] dp=new int[46];

   public Solution() {
        Arrays.fill(dp, -1);
    }
    public int climbStairs(int n) {
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];

        return  dp[n]=climbStairs(n-1)+climbStairs(n-2);
 }
}
