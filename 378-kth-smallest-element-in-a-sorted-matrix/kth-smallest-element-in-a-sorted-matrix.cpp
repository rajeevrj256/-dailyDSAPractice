class Solution {
public:

    bool check(int mid,vector<vector<int>>&matrix,int k){
        int n=matrix.size();
        int row=n-1;
        int col=0;
        int count=0;

        while(row>=0 && col<n){
            if(matrix[row][col]<=mid){
                count+=row+1;
                col++;
            }else{
                row--;
            }
        }

        return count>=k;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int i=matrix[0][0];
        int n=matrix.size();
        int j=matrix[n-1][n-1];
        int ans=i;
        while(i<=j){
          int mid=i+(j-i)/2;

          if(check(mid,matrix,k)){
            ans=mid;
            j=mid-1;
          }else{
            i=mid+1;
          }
        }

        return ans;
        
    }
};