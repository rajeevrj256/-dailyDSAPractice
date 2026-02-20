class Solution {
public:
   int dx[4]={-1,1,0,0};
   int dy[4]={0,0,-1,1};
    bool check(vector<vector<char>>&board,string res,string word,vector<vector<int>>&vis,int x,int y){
        int n=board.size();
        int m=board[0].size();
        
           if(board[x][y] != word[res.size()])
            return false;

        vis[x][y]=1;
        res.push_back(board[x][y]);
        if(res==word) return true;
        for(int i=0;i<4;i++){
            int nx=dx[i]+x;
            int ny=dy[i]+y;
            if(nx<n && ny<m && nx>=0 && ny>=0 && !vis[nx][ny]){
               
                if(check(board,res,word,vis,nx,ny)) return true;
            }
        }
        vis[x][y]=0;
        res.pop_back();

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
         int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(check(board,"",word,vis,i,j))
                    return true;
            }
        }

        return false;
    }
};