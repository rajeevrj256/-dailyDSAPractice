class Solution {
public:
   
    void backtracking(vector<vector<string>>&ans,vector<string>&res,int row,int n,vector<int>&cola,vector<int>&diga1,vector<int>&diga2){
        if(row>=n){
            ans.push_back(res);
            return;
        }
        for(int col=0;col<n;col++){
           
           if(cola[col] || diga1[row-col+n] || diga2[row+col]) continue;
            res[row][col]='Q';
            cola[col]=1;
            diga1[row-col+n]=1;
            diga2[row+col]=1;
            backtracking(ans,res,row+1,n,cola,diga1,diga2);
            res[row][col]='.';
             cola[col]=0;
            diga1[row-col+n]=0;
            diga2[row+col]=0;
           }
        }
    

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>res(n,string(n,'.'));
        vector<int>col(n,0);
        vector<int>diga1(2*n,0);
        vector<int>diga2(2*n,0);
        backtracking(ans,res,0,n,col,diga1,diga2);
        return ans;
    }
};