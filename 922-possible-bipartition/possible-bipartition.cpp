class Solution {
public:
    bool check(vector<vector<int>>&adj,vector<int>&color,int currcolor,int node){
        if(color[node]!=-1) return color[node]==currcolor;

        color[node]=currcolor;

        for(auto &it:adj[node]){
            if(!check(adj,color,!currcolor,it))return false;
        }

        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for(auto& it:dislikes){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>color(n+1,-1);

        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(!check(adj,color,0,i)) return false;
            }
        }

        return true;
    }
};