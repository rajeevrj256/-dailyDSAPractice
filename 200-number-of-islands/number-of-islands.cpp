class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    void dfs(vector<vector<char>>&grid,int row,int col){
        int n=grid.size();
        int m=grid[0].size();
        if(row>=n || col>=m || row<0 || col <0 || grid[row][col]=='0') return;
        grid[row][col]='0';
        for(int i=0;i<4;i++){
            int nx=row+dx[i];
            int ny=col+dy[i];
            dfs(grid,nx,ny);
        }


    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
   int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    ans++;
                }
            }
        }

        return ans;
    }
};