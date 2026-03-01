class Solution {
public:
    int ans=INT_MAX;
    int helper(vector<vector<int>>&matrix,vector<vector<int>>&dp,int row,int col){
         if(col<0 || col>matrix[0].size()-1 || row<0 || row>matrix.size()-1) return INT_MAX;
    if(row==matrix.size()-1) return matrix[row][col];
   
    if(dp[row][col]!=INT_MAX) return dp[row][col];


    int left=helper(matrix,dp,row+1,col-1);
    int right=helper(matrix,dp,row+1,col+1);
    int bottom=helper(matrix,dp,row+1,col);
int mini=min({left,right,bottom});
if(mini==INT_MAX) return dp[row][col]=INT_MAX;
    return dp[row][col]=matrix[row][col]+mini;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        for(int i=0;i<m;i++){
            ans=min(ans,helper(matrix,dp,0,i));
        }
       return ans;
    }
};