class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       //rowCut
       long long totalSum=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            totalSum+=grid[i][j];
        }

       }


       long long  curr=0;
       for(int i=0;i<n-1;i++){
          for(int j=0;j<m;j++){
            curr+=grid[i][j];
          }
          if(curr==totalSum-curr) return true;
       }
curr=0;
        for(int j=0;j<m-1;j++){
          for(int i=0;i<n;i++){
            curr+=grid[i][j];
          }
          if(curr==totalSum-curr) return true;
       }
       return false;
    }
};