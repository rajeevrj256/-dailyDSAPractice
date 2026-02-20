class Solution {
public:

    void dfs(vector<vector<string>>& accounts,unordered_map<string,vector<string>>&adj, unordered_set<string>&vis,string email,
        vector<vector<string>>&ans){
        vis.insert(email);
        ans.back().push_back(email);
        for(auto it:adj[email]){
            if(!vis.count(it)){
               dfs(accounts,adj,vis,it,ans);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,vector<string>>adj;

        for(auto it:accounts){
            for(int i=2;i<it.size();i++){
                adj[it[i]].push_back(it[i-1]);
                 adj[it[i-1]].push_back(it[i]);
            }
        }

        unordered_set<string>vis;
        vector<vector<string>>ans;

        for(auto it:accounts){
            if(!vis.count(it[1])){
            ans.push_back({it[0]});
            dfs(accounts,adj,vis,it[1],ans);
             sort(begin(ans.back())+1,end(ans.back()));
            }
        }

        return ans;
    }
};