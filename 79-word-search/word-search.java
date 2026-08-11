class Solution {

    boolean found=false;
    public void helper(char[][] board,String word,int i,int j,int index){
        int n=board.length;
        int m=board[0].length;
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!=word.charAt(index) || board[i][j]=='#') return;
        if(index==word.length()-1) {
            found= true;

            return;
        }
char temp=board[i][j];
        board[i][j]='#';


        helper(board,word,i,j+1,index+1);
          helper(board,word,i-1,j,index+1);
            helper(board,word,i,j-1,index+1);
              helper(board,word,i+1,j,index+1);

              board[i][j]=temp;;
    }
    public boolean exist(char[][] board, String word) {

     
  int n=board.length;
        int m=board[0].length;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                helper(board,word,i,j,0);
            }
                            if (found) {
                    return true;
                }

        }
       

        return found;
    }
}
