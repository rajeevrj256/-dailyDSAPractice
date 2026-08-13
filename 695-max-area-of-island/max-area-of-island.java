class Solution {
    int maxArea=0;
    public int helper(int[][] grid,int i,int j){
        int n=grid.length;
        int m=grid[0].length;

        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0) return 0;

        grid[i][j]=0;
        return 1+ helper(grid,i+1,j)+ helper(grid,i-1,j)+helper(grid,i,j+1)+helper(grid,i,j-1);

    }
    public int maxAreaOfIsland(int[][] grid) {
  int n=grid.length;
        int m=grid[0].length;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){

                    maxArea=Math.max(maxArea,helper(grid,i,j));
                }
            }
        }

        return maxArea;
    }
}
