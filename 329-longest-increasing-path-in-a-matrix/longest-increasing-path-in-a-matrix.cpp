class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    int dfs(vector<vector<int>>& matrix,int row,int col,int n,int m,vector<vector<int>>&dp){
        if(dp[row][col]!=-1) return dp[row][col];
       
        int len=1;
        for(int i=0;i<4;i++){
          int nx=row+dx[i];
          int ny=col+dy[i];

          if((nx<n && nx>=0 && ny<m && ny>=0) && matrix[nx][ny]<matrix[row][col]) {
            len=max(len,1+dfs(matrix,nx,ny,n,m,dp));
          };
        }

        return dp[row][col]=len;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int len=0;
        for(int i=0;i<n;i++ ){
            for(int j=0;j<m;j++){
               
                len=max(len,dfs(matrix,i,j,n,m,dp));
            }
        }

        return len;
    }
};