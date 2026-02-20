class Solution {
public:

    void dfs(vector<vector<int>>&adj,vector<int >&vis,int x){
        if(vis[x]) return;
        vis[x]=1;
        for(auto it:adj[x]){
            dfs(adj,vis,it);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int u=isConnected[i][j];
                if(u==1 && i!=j){
                adj[i].push_back(j);
                }
            }
        }
 int ans=0;
 vector<int >vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
            ans++;
            dfs(adj,vis,i);
            }
        }


        return ans;

    }
};