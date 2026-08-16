class Solution {
    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};

    public boolean dfs(int[][] height,int i,int j,boolean[][] vis,int ocean){
        int n=height.length;
        int m=height[0].length;

        
       
if(ocean==1){
        if(i==n-1 || j==m-1) return true;
}else{
    if(i==0 || j==0) return true;
}
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int nx=dx[k]+i;
            int ny=dy[k]+j;
             if(nx>=0 && ny>=0 && nx<n && ny<m && height[nx][ny]<=height[i][j] && !vis[nx][ny]) {
                if(dfs(height,nx,ny,vis,ocean)) return true;
             }

        }


        return false;
    }
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        int n=heights.length;
        int m=heights[0].length;
        List<List<Integer>>ans=new ArrayList<>();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                boolean[][] Pacificvis=new boolean[n][m];
                boolean[][] Atlanicvis=new boolean[n][m];

                boolean isPacificReached=dfs(heights,i,j,Pacificvis,1);
                boolean isAtlanticReached=dfs(heights,i,j,Atlanicvis,0);
                if(isPacificReached && isAtlanticReached) {
                    ans.add(Arrays.asList(i,j));
                }
            }
        }


        return ans;
    }
}
