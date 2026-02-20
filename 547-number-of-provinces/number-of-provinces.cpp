class Solution {
public:

    void dfs(vector<vector<int>>&adj,vector<int >&vis,int x){
        if(vis[x]) return;
        vis[x]=1;
        for(int i=0;i<adj.size();i++){
            if(adj[x][i]==1 && !vis[i])
            dfs(adj,vis,i);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
       
 int ans=0;
 vector<int >vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
            ans++;
            dfs(isConnected,vis,i);
            }
        }


        return ans;

    }
};