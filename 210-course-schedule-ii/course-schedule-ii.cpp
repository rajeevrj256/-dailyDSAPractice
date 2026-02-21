class Solution {
public:
    vector<int>ans;
    
    bool isCycle(vector<vector<int>>&adj,int node,vector<int>&vis,vector<int>&currRec){
        vis[node]=1;
        currRec[node]=1;

        for(auto& it:adj[node]){
            if(!vis[it]){
                if(isCycle(adj,it,vis,currRec)) return true;
            }else if(currRec[it]){
                return true;
            }
        }
        currRec[node]=0;
        ans.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto&  it:prerequisites){
            adj[it[0]].push_back(it[1]);

        }
        vector<int>vis(numCourses,0);
        vector<int>currRec(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i])
            if(isCycle(adj,i,vis,currRec)) return {};
        }
        
        return ans;


    }
};