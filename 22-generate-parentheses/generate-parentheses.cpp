class Solution {
public:
   void backtracking(int n,string str,int open,int close,vector<string>&res){
    if(open==n && close ==n){
        res.push_back(str);
    }

    if(open<n){
        backtracking(n,str+"(",open+1,close,res);
    }

    if(close<open){
        backtracking(n,str+")",open,close+1,res);
    }

   }
    vector<string> generateParenthesis(int n) {
        vector<string>res;

        backtracking(n,"",0,0,res);
        return res;
    }
};