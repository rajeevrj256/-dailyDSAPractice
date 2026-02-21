class Solution {
public:
    stack<int>st;
    unordered_set<int>vis;
    bool isCycleDetect(vector<vector<int>>&adj ,int course,vector<int>&vis,vector<int>&currRec){
        vis[course]=1;
        currRec[course]=1;
        st.push(course);
        for(auto it:adj[course]){
            if(!vis[it]){
                
                if(isCycleDetect(adj,it,vis,currRec)) return true;;
            }else if(currRec[it]){
                return true;
            }
        }

        currRec[course]=0;


        return false;
    }

   
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto& it:prerequisites){
            int u=it[1];
            int v=it[0];
            adj[u].push_back(v);
        }
        vector<int>vis(numCourses,0);
        vector<int>currRec(numCourses,0);

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                 if(isCycleDetect(adj,i,vis,currRec)) return false;

            }
        }
       
        return true;

    }
};