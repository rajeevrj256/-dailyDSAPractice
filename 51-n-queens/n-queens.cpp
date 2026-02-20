class Solution {
public:
    bool isValid(vector<string>&board,int row,int col,int n){
        for(int i=row-1;i>=0;i--){
            if(board[i][col]=='Q') return false;
        }
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++ ){
            if(board[i][j]=='Q') return false;
        }
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q') return false;

        }


        return true;


    }
    void backtracking(vector<vector<string>>&ans,vector<string>&res,int row,int n){
        if(row>=n){
            ans.push_back(res);
            return;
        }
        for(int col=0;col<n;col++){
           if(isValid(res,row,col,n)){
            res[row][col]='Q';
            backtracking(ans,res,row+1,n);
            res[row][col]='.';
           }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>res(n,string(n,'.'));
        backtracking(ans,res,0,n);
        return ans;
    }
};